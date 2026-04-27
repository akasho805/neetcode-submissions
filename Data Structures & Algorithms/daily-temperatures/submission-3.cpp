class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;

        st.push(n-1);
        res[n-1] = 0;

        for(int i=n-2;i>=0;i--)
        {
            // if(!st.empty() and temperatures[i]<temperatures[st.top()])
            // {
            //     res[i]=st.top()-i;     
            //     st.push();
            // }
            // else
            // {
                while(!st.empty() and temperatures[i]>=temperatures[st.top()])
                {
                    st.pop();
                }
                res[i] = st.empty() ? 0 : st.top()-i; 
                // st.push();
            // }
            
            st.push(i);
        }

        return res;

    }
};
