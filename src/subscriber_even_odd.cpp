#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class EvenOddSubscriber : public rclcpp::Node
{
public:
    EvenOddSubscriber() : Node("even_odd_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "numbers",
            10,
            std::bind(&EvenOddSubscriber::callback, this, std::placeholders::_1)
        );
    }

private:
    void callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        if (msg->data % 2 == 0)
        {
            RCLCPP_INFO(this->get_logger(), "EVEN: %d", msg->data);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "ODD: %d", msg->data);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<EvenOddSubscriber>());
    rclcpp::shutdown();
    return 0;
}
