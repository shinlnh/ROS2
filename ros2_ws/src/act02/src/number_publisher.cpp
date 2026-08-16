#include "act02/number_publisher.hpp"

#include <chrono>
#include <functional>

NumberPublisherNode::NumberPublisherNode()
: rclcpp::Node("number_publisher"), number_(0)
{
  publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
  timer_ = this->create_wall_timer(
    std::chrono::seconds(1), std::bind(&NumberPublisherNode::NumberPublisher, this));
  RCLCPP_INFO(
    this->get_logger(),
    "Activity 2 number_publisher will begin soon. Please wait for the number to be published ...");
}

void NumberPublisherNode::NumberPublisher()
{
  auto msg = example_interfaces::msg::Int64();
  msg.data = number_;
  publisher_->publish(msg);
}
