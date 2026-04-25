#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class SubscriberNode : public rclcpp::Node
{
public:
    SubscriberNode() : Node("subscriber_node")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "numbers",
            10,
            std::bind(&SubscriberNode::listener_callback, this, std::placeholders::_1)
        );
    }

private:
    void listener_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        if (msg->data > 5)
        {
            RCLCPP_INFO(this->get_logger(), "HIGH: %d", msg->data);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "LOW: %d", msg->data);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubscriberNode>());
    rclcpp::shutdown();
    return 0;
}
