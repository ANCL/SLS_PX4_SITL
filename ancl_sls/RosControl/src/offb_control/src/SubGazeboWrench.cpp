// Gazebo dependencies
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/gazebo_client.hh>

// ROS dependencies
#include <ros/ros.h>
#include <geometry_msgs/WrenchStamped.h>

// #include <iostream>

ros::Publisher pub, pub1, pub2, pub3;

void torquesCb(const ConstWrenchStampedPtr &_msg)
{
  // std::cout << "Received msg: " << std::endl;
  // std::cout << _msg->DebugString() << std::endl;
  geometry_msgs::WrenchStamped msgWrenchedStamped;
  // try WrenchStamped msgWrenchedStamped;
  msgWrenchedStamped.header.stamp = ros::Time::now();
  msgWrenchedStamped.wrench.force.x = _msg->wrench().force().x();
  msgWrenchedStamped.wrench.force.y = _msg->wrench().force().y();
  msgWrenchedStamped.wrench.force.z = _msg->wrench().force().z();
  msgWrenchedStamped.wrench.torque.x = _msg->wrench().torque().x();
  msgWrenchedStamped.wrench.torque.y = _msg->wrench().torque().y();
  msgWrenchedStamped.wrench.torque.z = _msg->wrench().torque().z();
  pub.publish(msgWrenchedStamped);
}

void torquesCb1(const ConstWrenchStampedPtr &_msg)
{
  // std::cout << "Received msg: " << std::endl;
  // std::cout << _msg->DebugString() << std::endl;
  geometry_msgs::WrenchStamped msgWrenchedStamped;
  // try WrenchStamped msgWrenchedStamped;
  msgWrenchedStamped.header.stamp = ros::Time::now();
  msgWrenchedStamped.wrench.force.x = _msg->wrench().force().x();
  msgWrenchedStamped.wrench.force.y = _msg->wrench().force().y();
  msgWrenchedStamped.wrench.force.z = _msg->wrench().force().z();
  msgWrenchedStamped.wrench.torque.x = _msg->wrench().torque().x();
  msgWrenchedStamped.wrench.torque.y = _msg->wrench().torque().y();
  msgWrenchedStamped.wrench.torque.z = _msg->wrench().torque().z();
  pub1.publish(msgWrenchedStamped);
}

void torquesCb2(const ConstWrenchStampedPtr &_msg)
{
  // std::cout << "Received msg: " << std::endl;
  // std::cout << _msg->DebugString() << std::endl;
  geometry_msgs::WrenchStamped msgWrenchedStamped;
  // try WrenchStamped msgWrenchedStamped;
  msgWrenchedStamped.header.stamp = ros::Time::now();
  msgWrenchedStamped.wrench.force.x = _msg->wrench().force().x();
  msgWrenchedStamped.wrench.force.y = _msg->wrench().force().y();
  msgWrenchedStamped.wrench.force.z = _msg->wrench().force().z();
  msgWrenchedStamped.wrench.torque.x = _msg->wrench().torque().x();
  msgWrenchedStamped.wrench.torque.y = _msg->wrench().torque().y();
  msgWrenchedStamped.wrench.torque.z = _msg->wrench().torque().z();
  pub2.publish(msgWrenchedStamped);
}

void torquesCb3(const ConstWrenchStampedPtr &_msg)
{
  // std::cout << "Received msg: " << std::endl;
  // std::cout << _msg->DebugString() << std::endl;
  geometry_msgs::WrenchStamped msgWrenchedStamped;
  // try WrenchStamped msgWrenchedStamped;
  msgWrenchedStamped.header.stamp = ros::Time::now();
  msgWrenchedStamped.wrench.force.x = _msg->wrench().force().x();
  msgWrenchedStamped.wrench.force.y = _msg->wrench().force().y();
  msgWrenchedStamped.wrench.force.z = _msg->wrench().force().z();
  msgWrenchedStamped.wrench.torque.x = _msg->wrench().torque().x();
  msgWrenchedStamped.wrench.torque.y = _msg->wrench().torque().y();
  msgWrenchedStamped.wrench.torque.z = _msg->wrench().torque().z();
  pub3.publish(msgWrenchedStamped);
}


int main(int argc, char **argv)
{
  ROS_INFO("Starting gazebo_transport_to_ros_topic node");

  // Load Gazebo
  gazebo::client::setup(argc, argv);

  // Load ROS
  ros::init(argc, argv, "gazebo_transport_to_ros_topic");

  // Create Gazebo node and init
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Create ROS node and init
  ros::NodeHandle n;

  // Get ROS params
  std::string gazebo_transport_topic_to_sub = "/gazebo/default/iris/iris/rotor_0_joint/force_torque/wrench";
  std::string ros_topic_to_pub = "/force_torque/rotor0";

  std::string gazebo_transport_topic_to_sub1 = "/gazebo/default/iris/iris/rotor_1_joint/force_torque/wrench";
  std::string ros_topic_to_pub1 = "/force_torque/rotor1";

  std::string gazebo_transport_topic_to_sub2 = "/gazebo/default/iris/iris/rotor_2_joint/force_torque/wrench";
  std::string ros_topic_to_pub2 = "/force_torque/rotor2";

  std::string gazebo_transport_topic_to_sub3 = "/gazebo/default/iris/iris/rotor_3_joint/force_torque/wrench";
  std::string ros_topic_to_pub3 = "/force_torque/rotor3";
  // std::string gazebo_transport_topic_to_sub = "/gazebo/default/iris/iris/rotor_0_joint/force_torque/wrench";
  // std::string ros_topic_to_pub = "/force_torque/rotor0";
  double ros_rate = 30;
  // ros::param::get("~gazebo_transport_topic_to_sub", gazebo_transport_topic_to_sub);
  // ros::param::get("~ros_rate", ros_rate);

  pub = n.advertise<geometry_msgs::WrenchStamped>(ros_topic_to_pub, 30);
  pub1 = n.advertise<geometry_msgs::WrenchStamped>(ros_topic_to_pub1, 30);
  pub2 = n.advertise<geometry_msgs::WrenchStamped>(ros_topic_to_pub2, 30);
  pub3 = n.advertise<geometry_msgs::WrenchStamped>(ros_topic_to_pub3, 30);

  // Listen to Gazebo force_torque sensor topic
  gazebo::transport::SubscriberPtr sub = node->Subscribe(gazebo_transport_topic_to_sub, torquesCb);
  gazebo::transport::SubscriberPtr sub1 = node->Subscribe(gazebo_transport_topic_to_sub1, torquesCb1);
  gazebo::transport::SubscriberPtr sub2 = node->Subscribe(gazebo_transport_topic_to_sub2, torquesCb2);
  gazebo::transport::SubscriberPtr sub3 = node->Subscribe(gazebo_transport_topic_to_sub3, torquesCb3);


  ros::Rate loop_rate(ros_rate); // 100 hz
  while(ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
  gazebo::shutdown();
  return 0;
}
