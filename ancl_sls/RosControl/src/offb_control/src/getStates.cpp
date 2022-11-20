#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <gazebo_msgs/LinkStates.h>
#include <mavros_msgs/State.h>
#include <geometry_msgs/WrenchStamped.h>
// #include <mavros_msgs/ActuatorControl.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/transform_datatypes.h>
#include <Eigen/Dense>
#include <offb_control/slsStates.h>
#include <offb_control/ActuatorControl0.h>

#include <FullLin1Control.h>
#include <QuasiController.h>
#include <QuasiControllerTrack.h>
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

# include <Eigen/Core>
# include <iostream>

// ------------------------------------------------------------------------------------------------------------------


template<typename T>
T saturate(T val, T min, T max) {
    return std::min(std::max(val, min), max);
}

template<typename T>
T sigmoidf(T x) {
    return x/(1+std::abs(x));
}

static void main_QuasiController(double dv[16], double dv2[6], double controller_output[4], double dv3[3], double dv1[2], double point[3]);

//
// Arguments    : void
// Return Type  : void
//
static void main_QuasiController(double dv[16], double dv2[6], double controller_output[4], double dv3[3], double dv1[2], double point[3])
{
  QuasiController(dv, dv1, dv2, dv3, point, controller_output);
}

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

geometry_msgs::WrenchStamped wrench0;
void rotors_cb(const geometry_msgs::WrenchStamped::ConstPtr& msg) {
    wrench0 = *msg;
}

geometry_msgs::WrenchStamped wrench1;
void rotors_cb1(const geometry_msgs::WrenchStamped::ConstPtr& msg) {
    wrench1 = *msg;
}

geometry_msgs::WrenchStamped wrench2;
void rotors_cb2(const geometry_msgs::WrenchStamped::ConstPtr& msg) {
    wrench2 = *msg;
}

geometry_msgs::WrenchStamped wrench3;
void rotors_cb3(const geometry_msgs::WrenchStamped::ConstPtr& msg) {
    wrench3 = *msg;
}


// ------------------------------------------------------------------------------------------

struct PendulumAngles {
    double alpha, beta; // roll(alpha) pitch(beta) yaw
}penangle,penangle2;

// void current_position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);
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


  double dv[16] = {};
  // double dv2[6] = {3.162277660169037e+03,4.790583473550029e+03,3.470550719426292e+03,1.366677835196229e+03,3.240775203934431e+02,40.597475793291565};
  double dv2[6] = {100.0000,  262.0775,  293.4230,  167.1719,   57.6346,   11.6305};
  double controller_output[4] = {};
  double controller_output1[4] = {};
  double dv3[7] = {1.55,0.15,1, 9.8066,0.0306,0.0306,0.0576};
  double dv1[2] = {10,5.4772};
  // double dv1[2] = {2.2361,    3.0777};
  double point[3] = {0, 0, -10};
  double TParam[4] = {16, 3, 1.5, 0.5};
	// ros::Subscriber position_state_sub = nh.subscribe<geometry_msgs::PoseStamped> ("/mavros/local_position/pose", 50, current_position_cb);
	ros::Subscriber gazebo_state_sub = nh.subscribe<gazebo_msgs::LinkStates>
            ("gazebo/link_states", 50, gazebo_state_cb);
    // ros::Publisher sls_state_topic = nh.
    // ros::Publisher actu0_pub = nh.advertise<mavros_msgs::ActuatorControl> ("/mavros/actuator_control", 1000);

  ros::Publisher sls_state_publish = nh.advertise<offb_control::slsStates> ("/offb_control/slsStates", 1000);
  ros::Publisher actu0_publish = nh.advertise<offb_control::ActuatorControl0> ("/offb_control/ActuatorControl0", 1000);
  ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 100, state_cb);
  ros::Subscriber rotor_thrust = nh.subscribe<geometry_msgs::WrenchStamped>("/force_torque/rotor0", 30, rotors_cb);
  ros::Subscriber rotor_thrust1 = nh.subscribe<geometry_msgs::WrenchStamped>("/force_torque/rotor1", 30, rotors_cb1);
  ros::Subscriber rotor_thrust2 = nh.subscribe<geometry_msgs::WrenchStamped>("/force_torque/rotor2", 30, rotors_cb2);
  ros::Subscriber rotor_thrust3 = nh.subscribe<geometry_msgs::WrenchStamped>("/force_torque/rotor3", 30, rotors_cb3);

  Eigen::Matrix4d KK;
  KK <<    -0.2200,    0.2000,    0.2200,   -0.2000,
    0.1300,   -0.1300,    0.1300,   -0.1300,
    0.0500,    0.0500,   -0.0500,   -0.0500,
    1.0000,    1.0000,    1.0000,    1.0000;

  ros::Rate rate(500);

	// ros::spin();
  offb_control::slsStates slsStatesPub;
  slsStatesPub.sls_states = {};
  offb_control::ActuatorControl0 actu0;
  actu0.group_mix = 0;

  double t0 = 0;
  double t65 = 0;
  double tref = 0;

	while(ros::ok()){
        slsStatesPub.sls_states[0] = sls_state1.x;
        slsStatesPub.sls_states[1] = sls_state1.y;
        slsStatesPub.sls_states[2] = sls_state1.z;
        slsStatesPub.sls_states[3] = sls_state1.alpha;
        slsStatesPub.sls_states[4] = sls_state1.beta;
        slsStatesPub.sls_states[5] = sls_state1.roll;
        slsStatesPub.sls_states[6] = sls_state1.pitch;
        slsStatesPub.sls_states[7] = sls_state1.yaw;
        slsStatesPub.sls_states[8] = sls_state1.vx;
        slsStatesPub.sls_states[9] = sls_state1.vy;
        slsStatesPub.sls_states[10] = sls_state1.vz;
        slsStatesPub.sls_states[11] = sls_state1.gamma_alpha;
        slsStatesPub.sls_states[12] = sls_state1.gamma_beta;
        slsStatesPub.sls_states[13] = sls_state1.omega_1;
        slsStatesPub.sls_states[14] = sls_state1.omega_2;
        slsStatesPub.sls_states[15] = sls_state1.omega_3;
        tref = ros::Time::now().toSec()-t0;
        t65 = 6.2831853071795862 * tref / TParam[0];
        slsStatesPub.ref_states[0] = TParam[1] * std::sin(t65);
        t65 = 12.566370614359172 * tref / TParam[0];
        slsStatesPub.ref_states[1] = TParam[2] * std::sin(t65);
        slsStatesPub.ref_states[2] = TParam[3] * std::sin(t65) + -10.0;
        sls_state_publish.publish(slsStatesPub);
        for (int i=0;i<16; i++){
          dv[i] = slsStatesPub.sls_states[i];
          // ROS_INFO_STREAM( "dv[i]: "<< i << " : " << dv[i] << "\n");
        }
        if( current_state.mode != "OFFBOARD"){
          t0 = ros::Time::now().toSec();
        }
        // ROS_INFO_STREAM( "First: "<< controller_output[0] << "\n");
        // main_QuasiController( dv, dv2, controller_output, dv3, dv1, point);
        QuasiControllerTrack( dv, ros::Time::now().toSec()-t0,dv1, dv2 , dv3, TParam,controller_output);
        // ROS_INFO_STREAM("time: " << ros::Time::now().toSec()-t0 );
        // FullLin1Control(dv, point, controller_output1);
        // ROS_INFO_STREAM("LQR: " << controller_output1[0] << "  " << controller_output1[1] << "  " << controller_output1[2] << "  " << controller_output1[3] << "\n");
        // ROS_INFO_STREAM("Quasi: " << controller_output[0]-16.35 << "  " << controller_output[1] << "  " << controller_output[2] << "  " << controller_output[3] << "\n");
                // local_pos_pub.publish(pose);
        actu0.group_mix = 0;
        //LQR Control
        // ********************************************************************************************************
        // actu0.controls[0] = saturate<double>(controller_output1[1]/190, -1, 1);
        // actu0.controls[1] = saturate<double>(controller_output1[2]/190, -1, 1);
        // actu0.controls[2] = saturate<double>(controller_output1[3]/190, -1, 1);
        // actu0.controls[3] = (controller_output1[0])/190 + 0.735292673;
        // ********************************************************************************************************
        // Quasi Control
        // ********************************************************************************************************
        actu0.controls[0] = saturate<double>(controller_output[1]/(1.8383), -1, 1);
        actu0.controls[1] = saturate<double>(controller_output[2]/(1.8383), -1, 1);
        // actu0.controls[2] = saturate<double>(controller_output[3]/(190910*1), -1, 1);
        actu0.controls[2] = saturate<double>(controller_output[3]/(190910), -1, 1);
        actu0.controls[3] = (controller_output[0]-16.67122)/20 + 0.8168;
        Eigen::Vector4d UU(wrench0.wrench.force.z, wrench1.wrench.force.z, wrench2.wrench.force.z, wrench3.wrench.force.z);
        Eigen::Vector4d UU0(controller_output[1], controller_output[2], controller_output[3], controller_output[0]);
        // std::cout<<"Diff:" << KK*UU - UU0 << std::endl;

        // std::cout<<"Quasi:"<< controller_output[0] <<std::endl<< "Rotor:" << 4*wrench0.wrench.force.z << std::endl <<
        // "difference:" << controller_output[0] - 4*wrench0.wrench.force.z << std::endl;
        // ********************************************************************************************************
        // ********************************************************************************************************
        // actu0.controls[0] = saturate<double>(controller_output[1]/12, -1, 1);
        // actu0.controls[1] = saturate<double>(controller_output[2]/12, -1, 1);
        // // actu0.controls[0] = std::tanh(controller_output[1]);
        // // actu0.controls[1] = std::tanh(controller_output[2]);
        // actu0.controls[2] = saturate<double>(controller_output[3]/12, -1, 1);
        // actu0.controls[3] = (controller_output[0]-16.35)/200 + 0.735292673;
        // ********************************************************************************************************
        // actu0.controls[0] = 0.01;
        // actu0.controls[1] = 0.01;
        // actu0.controls[2] = 0;
        // actu0.controls[3] = 0.74;
        actu0.controls[4] = 0;
        actu0.controls[5] = 0;
        actu0.controls[6] = 0;
        actu0.controls[7] = 0;
        actu0_publish.publish(actu0);
        // ROS_INFO_STREAM( "thrust: "<< controller_output[0] << "\n" << "z position: " <<slsStatesPub.sls_states[2]);
        ros::spinOnce();
        rate.sleep();
	}
	return 0;
}

// void current_position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){

//     double quatx = msg->pose.orientation.x;
//     double quaty = msg->pose.orientation.y;
//     double quatz = msg->pose.orientation.z;
//     double quatw = msg->pose.orientation.w;


//     tf2::Quaternion q(quatx,quaty,quatz,quatw);
//     tf2::Matrix3x3 m(q);
//     double roll, pitch, yaw;
//     m.getRPY(roll, pitch, yaw);

// }

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

    tf2::Quaternion quad_q(quadpose.orientation.x, quadpose.orientation.y, quadpose.orientation.z, quadpose.orientation.w);
    tf2::Matrix3x3 quad_m(quad_q);
    double quad_roll, quad_pitch, quad_yaw;
    quad_m.getRPY(quad_roll, quad_pitch, quad_yaw);

    sls_state1.x = loadpose.position.x;
    sls_state1.y = -loadpose.position.y;
    sls_state1.z = -loadpose.position.z;
    sls_state1.vx = msg->twist[10].linear.x;
    sls_state1.vy = -msg->twist[10].linear.y;
    sls_state1.vz = -msg->twist[10].linear.z;
    sls_state1.roll = quad_roll;
    sls_state1.pitch = -quad_pitch;
    sls_state1.yaw = -quad_yaw;
    sls_state1.omega_1 = quadtwist.angular.x;
    sls_state1.omega_2 = -quadtwist.angular.y;
    sls_state1.omega_3 = -quadtwist.angular.z;


    double Lx = (loadpose.position.x) - (quadpose.position.x) ;
    double Ly = (-loadpose.position.y) - (-quadpose.position.y) ;
    double Lz = (-loadpose.position.z) - (-quadpose.position.z) ;
    penangle = ToPenAngles( Lx, Ly, - Lz ); // in the paper the definition of n3 are opposite to the Z axis of gazebo
    sls_state1.alpha = penangle.alpha;
    sls_state1.beta = penangle.beta;

    double g_alpha, g_beta;
    g_beta = ((loadtwist.linear.x) - (quadtwist.linear.x))/std::cos(sls_state1.beta);
    g_alpha = ((-loadtwist.linear.y) - (-quadtwist.linear.y) - std::sin(sls_state1.alpha)*std::sin(sls_state1.beta)*g_beta)/(-std::cos(sls_state1.alpha)*std::cos(sls_state1.beta));

    sls_state1.gamma_alpha = g_alpha;
    sls_state1.gamma_beta = g_beta;
}


PendulumAngles ToPenAngles(double Lx,double Ly,double Lz) { //x=base.x
    PendulumAngles angles;
    double L = 1;


    // beta (y-axis rotation)
    double sinbeta = Lx/L;
    double cosbeta = Lz/(L*std::cos(angles.alpha));
    angles.beta = std::asin(sinbeta);
    // ROS_INFO_STREAM("beta: " << angles.beta << "\n");
    // alpha (x-axis rotation)

    double cosa_cosb = Lz/L;
    double sina_cosb = Ly/-L;
    angles.alpha = std::asin(sina_cosb/std::cos(angles.beta));
    // ROS_INFO_STREAM("alpha: " << angles.alpha << "\n");



    return angles;
}



