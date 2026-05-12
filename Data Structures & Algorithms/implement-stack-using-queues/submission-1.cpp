class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // pop q1 until there is only 1 element left
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        // pop the element
        int popEle = q1.front();
        q1.pop();
        // swap the two queues
        swap(q1, q2);
        return popEle;
    }
    
    int top() {
        // pop q1 until there is only 1 element left
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int topEle = q1.front();
        q2.push(topEle);
        q1.pop();
        swap(q1, q2);
        return topEle;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */