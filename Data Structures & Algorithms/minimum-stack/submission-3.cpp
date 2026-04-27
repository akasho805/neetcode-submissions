class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> st,minSt;

    void push(int val) {
        st.push(val);
        minSt.push(min(val,getMin()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(minSt.empty())
        {
            return INT_MAX;
        }
        return minSt.top();
    }
};
