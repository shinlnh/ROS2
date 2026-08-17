#!/usr/bin/env python3 
import rclpy 
from rclpy.node import Node 
from example_interfaces.srv import AddTwoInts 

class AddTwoIntsClient(Node): 
    def __init__(self): 
        super().__init__("add_two_ints_client")
        self.client_ = self.create_client(AddTwoInts, "add_two_ints")
    
    def call_add_two_ints(self, a, b): 
        while not self.client_.wait_for_service(1.0): 
            self.get_logger().warn("Waiting for Add Two Ints Server ... ")
        self.get_logger().info("Service is running ...")
            
        request = AddTwoInts.Request() 
        request.a = 3 
        request.b = 8 
        
        future = self.client_.call_async(request)
        future.add_done_callback(self.callback_call_add_two_ints) 
        
    def callback_call_add_two_ints(self, future): 
        response = future.result()
        self.get_logger().info("Got response: " + str(response.sum))
    
def main(args=None): 
    rclpy.init(args=args)
    node = AddTwoIntsClient() 
    node.call_add_two_ints(2,7)
    rclpy.spin(node) 
    rclpy.shutdown() 
    
    
