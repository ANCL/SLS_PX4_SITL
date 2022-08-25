#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <gazebo_msgs/LinkStates.h>
// #include <mavros_msgs/ActuatorControl.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/transform_datatypes.h>
#include <Eigen/Dense>

struct PendulumAngles {
    double alpha, beta; // roll(alpha) pitch(beta) yaw
}penangle,penangle2;

void current_position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);
void gazebo_state_cb(const gazebo_msgs::LinkStates::ConstPtr& msg);

PendulumAngles ToPenAngles(double Lx,double Ly,double Lz);

geometry_msgs::Pose quadpose;
geometry_msgs::Pose loadpose;
geometry_msgs::Pose pendpose;
geometry_msgs::Twist pendtwist;
geometry_msgs::Twist quadtwist;
geometry_msgs::Twist loadtwist;


//define the all 16 state of the Slung Load System
struct sls_state {
    double x, y, z, alpha, beta, roll, pitch, yaw, vx, vy, vz, gamma_alpha, gamma_beta, omega_1, omega_2, omega_3;
    // /mavros/local_position/pose
}sls_state1;


int main(int argc, char **argv){
	ros::init(argc, argv, "listener");
	ros::NodeHandle nh;

	ros::Subscriber position_state_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("/mavros/local_position/pose", 50, current_position_cb);
	ros::Subscriber gazebo_state_sub = nh.subscribe<gazebo_msgs::LinkStates>
            ("gazebo/link_states", 50, gazebo_state_cb);
    // ros::Publisher sls_state_topic = nh.
    // ros::Publisher actuator_setpoint_pub = nh.advertise<mavros_msgs::ActuatorControl> ("/mavros/actuator_control", 1000);
    //  ros::Publisher sls_state_publish = nh.advertise<sls_state> ("/sls_state", 1000);
    // ros::Rate rate(0.1);
	ros::spin();


	while(ros::ok()){

	}
	return 0;
}

void current_position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){

    sls_state1.x = msg -> pose.position.x;
    sls_state1.y = msg -> pose.position.y;
    sls_state1.z = msg -> pose.position.z;
    //quaternion to r p y
    double quatx = msg->pose.orientation.x;
    double quaty = msg->pose.orientation.y;
    double quatz = msg->pose.orientation.z;
    double quatw = msg->pose.orientation.w;

    // ROS_INFO_STREAM("quad position x" << sls_state1.x  << "y" << sls_state1.y << "z" << sls_state1.z << "Quotenion: " << quatx << quaty << quatz << quatw );

    // need sequency: pitch(y) roll(x) yaw(z)ROS_INFO_STREAM()
    tf2::Quaternion q(quatx,quaty,quatz,quatw);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    sls_state1.roll = roll;
    sls_state1.pitch = pitch;
    sls_state1.yaw = yaw;

    // sls_state1.

    // ROS_INFO_STREAM("quad position: " <<" x: " << msg ->pose.position.x << " y: "<< msg ->pose.position.y << " z: " << msg ->pose.position.z);
//     tf2::Ma
//     m.getRPY(sls_state1.roll, sls_state1.pitch, sls_state1.yaw);
}

void gazebo_state_cb(const gazebo_msgs::LinkStates::ConstPtr& msg){
    //ROS_INFO("I heard: [%s\n]", msg->name);
    //current_state = *msg;
    // cout<< msg->name[9]<< endl;

    quadpose = msg->pose[2];
    pendpose = msg->pose[9];
    loadpose = msg->pose[10]; // 10: pose of load; 9: pose of pendulum
    quadtwist = msg->twist[2];
    loadtwist = msg->twist[10];



    // tf2::Quaternion q(pendpose.orientation.x, pendpose.orientation.y, pendpose.orientation.z, pendpose.orientation.w );
    // tf2::Matrix3x3 m(q);
    // double roll, pitch, yaw;
    // m.getRPY(roll, pitch, yaw, 1);

    tf2::Quaternion quad_q(quadpose.orientation.x, quadpose.orientation.y, quadpose.orientation.z, quadpose.orientation.w );
    tf2::Matrix3x3 quad_m(quad_q);
    double quad_roll, quad_pitch, quad_yaw;
    quad_m.getRPY(quad_roll, quad_pitch, quad_yaw);

    sls_state1.x = loadpose.position.x;
    sls_state1.y = loadpose.position.y;
    sls_state1.z = loadpose.position.z;
    sls_state1.vx = msg->twist[10].linear.x;
    sls_state1.vy = msg->twist[10].linear.y;
    sls_state1.vz = msg->twist[10].linear.z;
    sls_state1.roll = quad_roll;
    sls_state1.pitch = quad_pitch;
    sls_state1.yaw = quad_yaw;
    sls_state1.omega_1 = msg->twist[10].angular.x;
    sls_state1.omega_2 = msg->twist[10].angular.y;
    sls_state1.omega_3 = msg->twist[10].angular.z;

    double Lx = loadpose.position.x - quadpose.position.x ;
    double Ly = loadpose.position.y - quadpose.position.y ;
    double Lz = loadpose.position.z - quadpose.position.z ;
    penangle = ToPenAngles( Lx, Ly, - Lz ); // in the paper the definition of n3 are opposite to the Z axis of gazebo
    sls_state1.alpha = penangle.alpha;
    sls_state1.beta = penangle.beta;
    // sls_state1.alpha = roll+ 3.1415926;
    // if (sls_state1.alpha > 3.1415926){
    //     sls_state1.alpha = sls_state1.alpha-2*3.1415926;
    // }
    // sls_state1.beta = pitch;

    // pendtwist = msg->twist[9];
    // sls_state1.gamma_alpha = pendtwist.angular.x;
    // if (cos(sls_state1.alpha) < 0.05){
    //     sls_state1.gamma_beta = pendtwist.angular.z/std::sin(sls_state1.alpha);
    // }else{
    //     sls_state1.gamma_beta = pendtwist.angular.y/std::cos(sls_state1.alpha);
    // }
    // double g_beta1 = pendtwist.angular.z/std::sin(sls_state1.alpha);

    double g_alpha, g_beta;
    g_beta = (loadtwist.linear.x - quadtwist.linear.x)/std::cos(sls_state1.beta);
    g_alpha = (loadtwist.linear.y - quadtwist.linear.y - std::sin(sls_state1.alpha)*std::sin(sls_state1.beta)*g_beta)/(-std::cos(sls_state1.alpha)*std::cos(sls_state1.beta));

    sls_state1.gamma_alpha = g_alpha;
    sls_state1.gamma_beta = g_beta;
    ROS_INFO_STREAM(sls_state1.alpha << "  "<<sls_state1.beta << "  "<<sls_state1.gamma_alpha<< " cos alpha: " << cos(sls_state1.alpha) << " gamma_beta: "<<sls_state1.gamma_beta);
    // ROS_INFO_STREAM("gamme_alpha: " << sls_state1.gamma_alpha << "  " << g_alpha <<  "  gamma_beta: " << sls_state1.gamma_beta << "  " << g_beta);

    // for (int x=0;x<3;x++){
    //     for (int y=0;y<3;y++){
    //         std::cout<<y << x <<m[y][x]<<"\n";
    //     }
    // }

    // ROS_INFO_STREAM("pend rpy, " <<"Roll: " <<roll << "Pitch: "<< pitch << "Yaw: " << yaw);
    // ROS_INFO_STREAM("quadpose, " <<" x: " << quadpose.position.x << " y: "<< quadpose.position.y << " z: " << quadpose.position.z);

    // ROS_INFO_STREAM(sls_state1.alpha << "  " << penangle.alpha << "  " << sls_state1.beta << "   "<< penangle.beta);
    // sls_state1.gamma_alpha << " gamma_beta: "<<sls_state1.gamma_beta <<

//      ROS_INFO_STREAM("load position" << Lx  << Ly << Lz );
}


PendulumAngles ToPenAngles(double Lx,double Ly,double Lz) { //x=base.x
    PendulumAngles angles;
    double L = 1;

    // alpha (x-axis rotation)

    double cosa_cosb = Lz/L;
    double sina_cosb = Ly/-L;
    angles.alpha = std::atan2(sina_cosb,cosa_cosb);

    // beta (y-axis rotation)
    double sinbeta = Lx/L;
    double cosbeta = Lz/(L*std::cos(angles.alpha));
    angles.beta = std::atan2(sinbeta,cosbeta);

    return angles;
}
