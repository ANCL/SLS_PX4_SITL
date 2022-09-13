/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ActuatorControl.h>

#include <gazebo_msgs/LinkStates.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/transform_datatypes.h>
// #include <tr>

#include <Eigen/Dense>
#include <offb_control/slsStates.h>
#include <offb_control/ActuatorControl0.h>


mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

struct sls_state {
    double x, y, z, alpha, beta, roll, pitch, yaw, vx, vy, vz, gamma_alpha, gamma_beta, omega_1, omega_2, omega_3;
    // /mavros/local_position/pose
}sls_state1;

void current_position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);

mavros_msgs::ActuatorControl actuator_setpoint;
void actuator_cb(const offb_control::ActuatorControl0::ConstPtr& msg){
    actuator_setpoint.group_mix = 0;
    actuator_setpoint.controls[0] = msg->controls[0];
    actuator_setpoint.controls[1] = msg->controls[1];
    actuator_setpoint.controls[2] = msg->controls[2];
    actuator_setpoint.controls[3] = msg->controls[3];
    actuator_setpoint.controls[4] = msg->controls[4];
    actuator_setpoint.controls[5] = msg->controls[5];
    actuator_setpoint.controls[6] = msg->controls[6];
    actuator_setpoint.controls[7] = msg->controls[7];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 100, state_cb);
    ros::Subscriber position_state_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("/mavros/local_position/pose", 100, current_position_cb);
    ros::Subscriber actuator_sub = nh.subscribe<offb_control::ActuatorControl0>("/offb_control/ActuatorControl0", 1000, actuator_cb);
    // ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamp ed> ("mavros/setpoint_position/local", 10);
    ros::Publisher actuator_setpoint_pub = nh.advertise<mavros_msgs::ActuatorControl> ("/mavros/actuator_control", 1000);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(1000);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    // geometry_msgs::PoseStamped pose;
    // pose.pose.position.x = 5;
    // pose.pose.position.y = 5;
    // pose.pose.position.z = 5;


    //send a few setpoints before starting
    // for(int i = 100; ros::ok() && i > 0; --i){
    //     // local_pos_pub.publish(pose);
    //     actuator_setpoint.group_mix = 0;
    //     actuator_setpoint.controls[0] = 0;
    //     actuator_setpoint.controls[1] = 0;
    //     actuator_setpoint.controls[2] = 0;
    //     // std::cout<< actuator_setpoint.controls[2];
    //     actuator_setpoint.controls[3] = (10-sls_state1.z)/10 * 0.2+0.7;
    //     actuator_setpoint.controls[4] = 0;
    //     actuator_setpoint.controls[5] = 0;
    //     actuator_setpoint.controls[6] = 0;
    //     actuator_setpoint.controls[7] = 0;
    //     actuator_setpoint_pub.publish(actuator_setpoint);
    //     ROS_INFO_STREAM(actuator_setpoint.controls[3]);
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }


        // actuator_setpoint.group_mix = 0;
        // actuator_setpoint.controls[0] = 0;
        // actuator_setpoint.controls[1] = 0;
        // actuator_setpoint.controls[2] = 0;
        // actuator_setpoint.controls[3] = (10-sls_state1.z)/10 * 0.1+0.7;
        // actuator_setpoint.controls[4] = 0;
        // actuator_setpoint.controls[5] = 0;
        // actuator_setpoint.controls[6] = 0;
        // actuator_setpoint.controls[7] = 0;
        // local_pos_pub.publish(pose);
        actuator_setpoint_pub.publish(actuator_setpoint);

        ros::spinOnce();
        rate.sleep();
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

    // need sequency: pitch(y) roll(x) yaw(z)
    // tf2::Quaternion q(quatx,quaty,quatz,quatw);
    // tf2::Matrix3x3 m(q);
    // double roll, pitch, yaw;
    // m.getRPY(roll, pitch, yaw);

    // ROS_INFO_STREAM("quad position: " <<" x: " << msg ->pose.position.x << " y: "<< msg ->pose.position.y << " z: " << msg ->pose.position.z);
//     tf2::Ma
//     m.getRPY(sls_state1.roll, sls_state1.pitch, sls_state1.yaw);
}


