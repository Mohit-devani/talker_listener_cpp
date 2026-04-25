#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("publisher_node"), count_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("numbers", 10);
        timer_ = this->create_wall_timer(
            1s, std::bind(&PublisherNode::publish_number, this));
    }

private:
    void publish_number()
    {
        auto msg = std_msgs::msg::Int32();
        msg.data = count_;

        publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Publishing: %d", msg.data);

        count_++;
    }

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}
