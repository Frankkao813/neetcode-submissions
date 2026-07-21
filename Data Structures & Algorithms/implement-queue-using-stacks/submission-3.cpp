class MyQueue {
    // idea: there are two stacks
    // The first stack: utilized in the push operation
    // The second stack: utilized in pop() and peek(). 
    // only transfer elements when the second stack is empty
    stack<int> st1;
    stack<int> st2;
    void refill(){
        if (st2.empty()){
            while (!st1.empty()){
                int curr = st1.top();
                st1.pop();
                st2.push(curr);
            }
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        st1.push(x);
    }

    
    int pop() {
        if (empty()) return -1;

        refill();
        int number = st2.top();
        st2.pop();
        return number;

    }
    
    int peek() {
        if (empty()) return -1;
        refill();
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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