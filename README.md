# ROS 2 Talker Listener (C++)

This project demonstrates a simple ROS 2 publisher and subscriber in C++.

## Nodes

### Publisher Node
- Publishes integer values to topic: `numbers`
- Publishes one number every 1 second

### Subscriber Node
- Subscribes to topic: `numbers`
- Prints HIGH if value > 5, else LOW

## How to Build

```bash
colcon build
