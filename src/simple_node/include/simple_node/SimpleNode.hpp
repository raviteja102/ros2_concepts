#ifndef SIMPLE_NODE__SIMPLE_NODE_HPP
#define SIMPLE_NODE__SIMPLE_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>

class SimpleNode : public rclcpp::Node
{
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

#endif // SIMPLE_NODE__SIMPLE_NODE_HPP