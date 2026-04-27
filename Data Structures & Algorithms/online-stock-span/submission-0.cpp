class StockSpanner {
public:
    StockSpanner() {
        
    }

    stack<pair<int,int>> st;
    
    int next(int price) {
        if(st.empty())
        {
            st.push({price,1});
            return 1;
        }

        int span =1;
        while(!st.empty() and price>=st.top().first)
        {
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */