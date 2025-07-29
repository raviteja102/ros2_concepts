#include "simple_node/SimpleNode.hpp"
#include "std_msgs/msg/string.hpp"

SimpleNode::SimpleNode() : Node("simple_node")
{
    RCLCPP_INFO(this->get_logger(), "Constructor for the Simple Node initialize the key elements needed for the node");
    this->declare_parameter<std::string>("topic_name_", "chatter");
    this->declare_parameter<int>("time_interval_", 1000);
    this->get_parameter("topic_name_", topic_name_);
    this->get_parameter("time_interval_", time_interval_);

    publisher_ = this->create_publisher<std_msgs::msg::String>(topic_name_, 10);

    subscriber = this->create_subscription<std_msgs::msg::String>(topic_name_, 10, std::bind(&SimpleNode::subscriberCallback, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(std::chrono::milliseconds(time_interval_), std::bind(&SimpleNode::timerCallback, this));
}

void SimpleNode::subscriberCallback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Message received from publisher and here is message and counter %s  %d", msg->data.c_str(), ++counter_);
}

void SimpleNode::timerCallback()
{
    std_msgs::msg::String message;
    message.data = "Hello from SimpleNode ";
    publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "Publishing messages with a interval of %d milliseconds, with the message %s", time_interval_, message.data.c_str());
}

int main(int argc, const char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleNode>());
    rclcpp::shutdown();

    return 0;
}