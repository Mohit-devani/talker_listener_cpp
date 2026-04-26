## Nodes

### 1. Number Publisher
- Publishes integer values to topic: `numbers`
- Runs every 1 second

### 2. Number Subscriber
- Subscribes to `numbers`
- Prints HIGH if value > 5, else LOW

### 3. Even/Odd Subscriber
- Subscribes to `numbers`
- Prints whether number is EVEN or ODD

### 4. Keyboard Publisher
- Takes input from keyboard
- Publishes string commands to topic: `commands`

### 5. Command Listener
- Subscribes to `commands`
- Processes user-entered commands
