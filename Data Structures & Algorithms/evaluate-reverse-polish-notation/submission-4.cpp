class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();

        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+" ||tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int second=st.top();st.pop();
                int first = st.top();st.pop();
                switch(tokens[i][0])
                {
                    case '+': 
                        st.push(first+second);
                        break;
                    case '-': 
                        st.push(first-second);
                        break;
                    case '*': 
                        st.push(first*second);
                        break;
                    case '/': 
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
