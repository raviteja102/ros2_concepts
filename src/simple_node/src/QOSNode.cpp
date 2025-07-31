#include "simple_node/QOSNode.hpp"
#include <string>

QOSNode::QOSNode() : Node("qos_node") {
  RCLCPP_INFO(this->get_logger(), "QOS Node initialized");

  this->declare_parameter<std::string>("topic_name", "qos_topic");
  this->declare_parameter<int>("timer_interval", 1000);

  this->get_parameter("topic_name", topic_name_);
  this->get_parameter("timer_interval", time_interval_);

  rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
  qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  qos_profile.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);
  qos_profile.history(RMW_QOS_POLICY_HISTORY_KEEP_LAST);

  publisher_ =
      this->create_publisher<std_msgs::msg::String>(topic_name_, qos_profile);

  subscriber_ = this->create_subscription<std_msgs::msg::String>(
      topic_name_, qos_profile,
      std::bind(&QOSNode::subscriberCallback, this, std::placeholders::_1));

  timer_ = this->create_wall_timer(std::chrono::milliseconds(time_interval_),
                                   std::bind(&QOSNode::timerCallback, this));
}

void QOSNode::subscriberCallback(std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
}

void QOSNode::timerCallback() {
  std_msgs::msg::String msg;
  msg.data = "Hello from QOSNode";
  publisher_->publish(msg);
  RCLCPP_INFO(this->get_logger(), "Published: '%s'", msg.data.c_str());
}

int main(int argc, char *argv[]) {

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<QOSNode>());
  rclcpp::shutdown();
}
