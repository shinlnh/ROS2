#!/usr/bin/python3
from distro import name

import rclpy 
from rclpy.node import Node

class FirstNode(Node):
    def __init__(self):
        super().__init__("py_test") 
        self.get_logger().info("Hello ROS 2")
        self.timer = self.create_timer(1.0, self.timer_callback)
        self._counter = 0
    
    def timer_callback(self): 
        self._counter += 1
        self.get_logger().info(f"Hello {self._counter}")

def main(args=None):
    rclpy.init(args=args)
    # Create the first node in ROS 2
    node = FirstNode()
    rclpy.spin(node); 
    rclpy.shutdown()

if __name__ == "__main__":
    main()

    

