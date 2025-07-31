// Copyright 2025 Ravi
// Licensed under the Apache License, Version 2.0

#include "simple_node/SimpleNode.hpp"
#include <memory>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleNode>());
  rclcpp::shutdown();
  return 0;
}
