class MinStack {
public:
    // method: 2 stack method
    // The first is normal, but the second record the minimum at this point

    stack<int> st;
    stack<int> minSt;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty()){
            minSt.push(val);
        }
        else{
            minSt.push(min(val, minSt.top()));
        }
    }
    
    void pop() {
        // realization: minSt records the minimum of the stack at each depth
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
