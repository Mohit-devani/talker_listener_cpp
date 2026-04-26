#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CommandListener : public rclcpp::Node
{
public:
    CommandListener() : Node("command_listener")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "commands",
            10,
            std::bind(&CommandListener::callback, this, std::placeholders::_1)
        );
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Robot received: %s", msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CommandListener>());
    rclcpp::shutdown();
    return 0;
}
