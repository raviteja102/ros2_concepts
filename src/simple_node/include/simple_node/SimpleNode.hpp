// Copyright 2025 Ravi
// Licensed under the Apache License, Version 2.0

#ifndef SRC_SIMPLE_NODE_INCLUDE_SIMPLE_NODE_SIMPLENODE_HPP_
#define SRC_SIMPLE_NODE_INCLUDE_SIMPLE_NODE_SIMPLENODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>

class SimpleNode : public rclcpp::Node {
 public:
  SimpleNode();

 private:
  std::string topic_name_;
  int time_interval_;
  int counter_ = 0;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;
  rclcpp::TimerBase::SharedPtr timer_;

  void subscriberCallback(const std_msgs::msg::String::SharedPtr msg);
  void timerCallback();
};

#endif // SRC_SIMPLE_NODE_INCLUDE_SIMPLE_NODE_SIMPLENODE_HPP_
