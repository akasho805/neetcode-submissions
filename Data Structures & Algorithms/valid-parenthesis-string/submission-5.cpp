class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length(),left=0,right=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                left++;right++;
            }
            else if(s[i] ==')')
            {
                left--;right--;
            }
            else
            {
                left--;right++;
            }
            if(right<0)
            {
                return false;
            }
            left =max(left,0);
        }

        return left == 0;

        //2 stack linear time but extra o(n) space
        // stack<int> st1,st2;
        // int i=0;

        // while(i<s.length())
        // {
        //     if(s[i] == '(')
        //     {
        //         st1.push(i);
        //     }
        //     else if(s[i] =='*')
        //     {
        //         st2.push(i);
        //     }
        //     else
        //     {
        //         if(!st1.empty())
        //         {
        //             st1.pop();
        //         }
        //         else if(!st2.empty())
        //         {
        //             st2.pop();
        //         }
        //         else
        //         {
        //             return false;
        //         }
        //     }
        //     i++;
        // }

        // while(!st1.empty())
        // {
        //     if(!st2.empty() && st2.top() > st1.top())
        //     {
        //         st1.pop();
        //         st2.pop();
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }

        // return true;
    }
};
