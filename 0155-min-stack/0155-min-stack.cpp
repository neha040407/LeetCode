class MinStack {
    stack<int> st;
    stack<int> minst;   //storing min when the new element is added
public:
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);
        if(st.size() == 1 || value < minst.top()){
            minst.push(value);
        }
        else{
            minst.push(minst.top());
        }
        return;
    }
    
    void pop() {
        minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */