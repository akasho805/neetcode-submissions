class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> st,minSt;

    int minimum = INT_MAX;

    void push(int val) {
        st.push(val);
        minimum = min(val,minimum);
        minSt.push(minimum);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
        if(!minSt.empty())
        {
            minimum = minSt.top();
        }
        else
        {
            minimum = INT_MAX; 
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minimum;
    }
};
