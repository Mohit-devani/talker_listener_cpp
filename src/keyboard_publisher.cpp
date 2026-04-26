#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>

class KeyboardPublisher : public rclcpp::Node
{
public:
    KeyboardPublisher() : Node("keyboard_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("commands", 10);

        // Timer runs repeatedly
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&KeyboardPublisher::read_input, this)
        );
    }

private:
    void read_input()
    {
        std::string input;

        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (!input.empty())
        {
            auto msg = std_msgs::msg::String();
            msg.data = input;

            publisher_->publish(msg);

            RCLCPP_INFO(this->get_logger(), "Sent: %s", msg.data.c_str());
        }
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("keyboard_publisher");
    auto publisher = node->create_publisher<std_msgs::msg::String>("commands", 10);

    std::string input;

    while (rclcpp::ok())
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (!input.empty())
        {
            auto msg = std_msgs::msg::String();
            msg.data = input;

            publisher->publish(msg);

            RCLCPP_INFO(node->get_logger(), "Sent: %s", msg.data.c_str());
        }
    }

    rclcpp::shutdown();
    return 0;
}
