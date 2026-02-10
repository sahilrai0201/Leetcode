class MyQueue {

    int* arr;
    int front;
    int rear;
    int size;

public:
    MyQueue() {
        //implement the constructor
        size = 10000;
        arr = new int[size];
        front = 0;
        rear = 0;
        
    }
    
    void push(int x) {
        if(rear < size){
            arr[rear] = x;
            rear++;
        }
    }
    
    int pop() {
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            front++;

            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    
    int peek() {
        if(front == rear){
            return -1;
        }
        return arr[front];
    }
    
    bool empty() {
        return front == rear;
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */