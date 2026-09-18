#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // Input stack
    std::stack<int> s2; // Output stack

    // Helper to transfer elements when s2 is empty
    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transfer();
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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