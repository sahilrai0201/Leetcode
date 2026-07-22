class MyQueue {
public:
    stack<int> input, output;

    MyQueue() {
        
    }

    void push(int x) {
        input.push(x);                  // Always push into input stack
    }

    int pop() {
        // Transfer only if output is empty
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());   // Reverse the order
                input.pop();
            }
        }

        int frontElement = output.top();    // Queue front
        output.pop();
        return frontElement;
    }

    int peek() {
        // Transfer only if output is empty
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();    // Front of queue
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};