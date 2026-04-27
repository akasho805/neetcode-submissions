class MinStack {
public:
    MinStack() {
        
    }
    
    stack<long long> st;
    long long mini;

    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mini = val;
            return;
        }

        if(val>=mini)
        {
            st.push(val);
        }
        else
        {
            st.push(2LL* val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty())
        {
            return;
        }

        if(st.top()>=mini)
        {
            st.pop();
        }
        else 
        {
            mini = 2LL * mini - st.top(); 
            st.pop();
        }  
    }
    
    int top() {
        if(st.empty())
        {
            return -1;
        }
        if(st.top()>=mini)
        {
            return st.top();
        }
        else
        {
            return mini;
        }
    }
    
    int getMin() {
        if(st.empty())
        {
            return -1;
        }
        return mini;
    }
};
