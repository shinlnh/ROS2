#include "act02/number_counter.hpp"

#include <cinttypes>
#include <functional>

NumberCounterNode::NumberCounterNode()
: rclcpp::Node("number_counter"), counter_(0)
{
  subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
    "number", 10,
    std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1));
  publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
  RCLCPP_INFO(
    this->get_logger(),
    "Activity 2 Number Counter is running. Please wait for the number to be received ...");
}

void NumberCounterNode::callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
{
  counter_ += msg->data;
  counter_ += 2;
  RCLCPP_INFO(
    this->get_logger(), "Activity 2 Number Counter received: %" PRId64, counter_);

  auto new_msg = example_interfaces::msg::Int64();
  new_msg.data = counter_;
  publisher_->publish(new_msg);
  RCLCPP_INFO(
    this->get_logger(), "Activity 2 Number Counter published: %" PRId64, new_msg.data);
}
