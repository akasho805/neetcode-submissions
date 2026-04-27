class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();

        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+" ||tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int second,first;
                switch(tokens[i][0])
                {
                    case '+': 
                        second = st.top();
                        st.pop();
                        first = st.top();
                        st.pop();
                        st.push(first+second);
                        break;
                    case '-': 
                        second = st.top();
                        st.pop();
                        first = st.top();
                        st.pop();
                        st.push(first-second);
                        break;
                    case '*': 
                        second = st.top();
                        st.pop();
                        first = st.top();
                        st.pop();
                        st.push(first*second);
                        break;
                    case '/': 
                        second = st.top();
                        st.pop();
                        first = st.top();
                        st.pop();
                        st.push(first/second);
                        break;
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
