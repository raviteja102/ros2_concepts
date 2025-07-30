// Copyright 2025 Ravi
// Licensed under the Apache License, Version 2.0

#ifndef SIMPLE_NODE__SIMPLE_NODE_HPP_
#define SIMPLE_NODE__SIMPLE_NODE_HPP_

//  Project-specific headers
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

//  C++ system headers
#include <string>

class SimpleNode : public rclcpp::Node {
public:
  // Constructor declaration
  SimpleNode();

private:
  // Member variables
  std::string topic_name_;
  int time_interval_;
  int counter_ = 0;

  // Publisher and Subscriber with consistent naming convention
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;

  // Callback methods
  void subscriberCallback(const std_msgs::msg::String::SharedPtr msg);
  void timerCallback();
};

#endif // SIMPLE_NODE__SIMPLE_NODE_HPP_
