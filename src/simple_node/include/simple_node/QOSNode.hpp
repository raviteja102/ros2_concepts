#ifndef _QOS_NODE__QOS_NODE_HPP_
#define _QOS_NODE__QOS_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class QOSNode : public rclcpp::Node {
public:
  QOSNode();

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;

  void subscriberCallback(std_msgs::msg::String::SharedPtr msg);
  void timerCallback();

  std::string topic_name_;
  int time_interval_;
};
#endif //_QOS_NODE__QOS_NODE_HPP_
