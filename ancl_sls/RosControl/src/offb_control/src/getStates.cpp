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
#include <offb_control/slsStates.h>
#include <offb_control/ActuatorControl0.h>

#include <FullLin1Control.h>
#include <QuasiController.h>
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// ------------------------------------------------------------------------------------------------------------------

static void argInit_1x16_real_T(double result[16]);

static void argInit_1x2_real_T(double result[2]);

static void argInit_1x3_real_T(double result[3]);

static void argInit_1x6_real_T(double result[6]);

static double argInit_real_T();

template<typename T>
T saturate(T val, T min, T max) {
    return std::min(std::max(val, min), max);
}

static void main_QuasiController(double dv[16], double dv2[6], double controller_output[4], double dv3[3], double dv1[2], double point[3]);

// Function Definitions
//
// Arguments    : double result[16]
// Return Type  : void
//
static void argInit_1x16_real_T(double result[16])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 16; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 3; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[6]
// Return Type  : void
//
static void argInit_1x6_real_T(double result[6])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 6; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_QuasiController(double dv[16], double dv2[6], double controller_output[4], double dv3[3], double dv1[2], double point[3])
{
  // Initialize function 'QuasiController' input arguments.
  // Initialize function input argument 'x'.
  // Initialize function input argument 'Kv2'.
  // Initialize function input argument 'Kv6'.
  // Initialize function input argument 'M'.
  // Call the entry-point 'QuasiController'.
  // argInit_1x16_real_T(dv);
  // argInit_1x2_real_T(dv1);
  // argInit_1x6_real_T(dv2);
  // argInit_1x3_real_T(dv3);
  QuasiController(dv, dv1, dv2, dv3, point, controller_output);
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
  double dv2[6] = {3.162277660169037e+03,4.790583473550029e+03,3.470550719426292e+03,1.366677835196229e+03,3.240775203934431e+02,40.597475793291565};
  double controller_output[4] = {};
  double dv3[3] = {1.535,0.1,1};
  double dv1[2] = {10,5.4772};
  double point[3] = {1, 1, -9.3};
	// ros::Subscriber position_state_sub = nh.subscribe<geometry_msgs::PoseStamped> ("/mavros/local_position/pose", 50, current_position_cb);
	ros::Subscriber gazebo_state_sub = nh.subscribe<gazebo_msgs::LinkStates>
            ("gazebo/link_states", 50, gazebo_state_cb);
    // ros::Publisher sls_state_topic = nh.
    // ros::Publisher actu0_pub = nh.advertise<mavros_msgs::ActuatorControl> ("/mavros/actuator_control", 1000);

  ros::Publisher sls_state_publish = nh.advertise<offb_control::slsStates> ("/offb_control/slsStates", 1000);
  ros::Publisher actu0_publish = nh.advertise<offb_control::ActuatorControl0> ("/offb_control/ActuatorControl0", 1000);
  ros::Rate rate(500);

	// ros::spin();
  offb_control::slsStates slsStatesPub;
  slsStatesPub.sls_states = {};
  offb_control::ActuatorControl0 actu0;
  actu0.group_mix = 0;


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
        sls_state_publish.publish(slsStatesPub);
        for (int i=0;i<16; i++){
          dv[i] = slsStatesPub.sls_states[i];
          // ROS_INFO_STREAM( "dv[i]: "<< i << " : " << dv[i] << "\n");
        }
        // ROS_INFO_STREAM( "First: "<< controller_output[0] << "\n");
        // main_QuasiController( dv, dv2, controller_output, dv3, dv1, point);
        FullLin1Control(dv, point, controller_output);
                // local_pos_pub.publish(pose);
        actu0.group_mix = 0;
        // actu0.controls[0] = saturate<double>(controller_output[1],-20,20)/2000;
        // actu0.controls[1] = saturate<double>(controller_output[2],-20,20)/2000;
        // actu0.controls[2] = saturate<double>(controller_output[3],-10,10)/2000;
        // actu0.controls[2] = 0;
        // actu0.controls[3] = saturate<double>((saturate<double>(controller_output[0],0,50)-16.35)/800 + 0.74,0.5,0.95);
        // actu0.controls[3] = saturate<double>((saturate<double>(controller_output[0],0,50))/800 + 0.74,0.5,0.95);
        actu0.controls[0] = saturate<double>(controller_output[1], -100, 100)/200;
        actu0.controls[1] = saturate<double>(controller_output[2], -100, 100)/200;
        actu0.controls[2] = saturate<double>(controller_output[3], -100, 100)/200;
        actu0.controls[3] = controller_output[0]/200+0.735292673;
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
