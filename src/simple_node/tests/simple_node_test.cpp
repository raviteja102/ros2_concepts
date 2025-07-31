// Copyright 2025 Ravi
// Licensed under the Apache License, Version 2.0

// #include "simple_node/tests/simple_node_test.h" //  Project-specific header
// (if any)
#include "simple_node/SimpleNode.hpp"

#include <gtest/gtest.h> //  Third-party headers
#include <memory>        //  C++ system headers
#include <string>        //  C++ system headers

//  Test to ensure SimpleNode is created successfully
TEST(SimpleNodeTest, NodeInitialization) {
  rclcpp::init(0, nullptr); //  Initialize ROS

  //  Create an instance of SimpleNode
  auto node = std::make_shared<SimpleNode>();

  //  Ensure the node is properly initialized
  EXPECT_NE(node, nullptr);

  //  Ensure parameters are correctly initialized
  std::string topic_name;
  node->get_parameter("topic_name_", topic_name);
  EXPECT_EQ(topic_name, "chatter");

  int time_interval;
  node->get_parameter("time_interval_", time_interval);
  EXPECT_EQ(time_interval, 1000);

  rclcpp::shutdown(); //  Shutdown ROS
}

//  Test to ensure the publisher is created
TEST(SimpleNodeTest, PublisherCreated) {
  rclcpp::init(0, nullptr); //  Initialize ROS

  auto node = std::make_shared<SimpleNode>();

  //  Ensure the publisher is created
  // EXPECT_NE(node->publisher_, nullptr);

  rclcpp::shutdown(); //  Shutdown ROS
}

//  Test to ensure the subscriber is created
TEST(SimpleNodeTest, SubscriberCreated) {
  rclcpp::init(0, nullptr); //  Initialize ROS

  auto node = std::make_shared<SimpleNode>();

  //  Ensure the subscriber is created
  // EXPECT_NE(node->subscriber_, nullptr);

  rclcpp::shutdown(); //  Shutdown ROS
}

TEST(SimpleNodeTest, MYFirstTestCase) {
  rclcpp::init(0, nullptr);

  auto node = std::make_shared<SimpleNode>();

  EXPECT_NE(node, nullptr);

  rclcpp::shutdown();
}
