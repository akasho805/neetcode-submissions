class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;

        string curr = "";
        int k = 0;

        for(char ch : s)
        {
            if(isdigit(ch))
            {
                k = k * 10 + (ch - '0');
            }
            else if(ch == '[')
            {
                countSt.push(k);
                strSt.push(curr);

                // reset
                k = 0;
                curr = "";
            }
            else if(ch == ']')
            {
                int repeat = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();

                string temp = "";
                for(int i = 0; i < repeat; i++)
                {
                    temp += curr;
                }

                curr = prev + temp;
            }
            else
            {
                curr += ch;
            }
        }

        return curr;
    }
};

//mental model

// At '[':

// Push:
// - current string
// - current number
// Reset both

// At ']':
// curr = prev + (curr * k)



//above is cleaner implementation

// class Solution {
// public:
//     string decodeString(string s) {
//         stack<int> st1;
//         vector<string> st2;

        
//         bool last_num = false;

//         for(auto ch: s)
//         {
//             if(isdigit(ch))
//             {
//                 if(last_num)
//                 {
//                     int val = st1.top();
//                     st1.pop();
//                     st1.push((val*10)+(ch-'0'));
//                 }
//                 else
//                 {
//                     st1.push(ch-'0');  
//                 }
//                 last_num = true;
//             }
//             else if(ch==']')
//             {
//                 last_num = false;
//                 string curr = "";
//                 while(!st2.empty() and st2.back()!="[")
//                 {
//                     curr = st2.back() + curr;
//                     st2.pop_back();
//                 }
//                 if(!st2.empty())
//                 {
//                     st2.pop_back();
//                 }
//                 // st2.push(curr);  

//                 if(!st1.empty())
//                 {
//                     string res=curr;
//                     for(int i =1;i<st1.top();i++)
//                     {
//                         res+=curr;
//                     }
//                     st1.pop();
//                     st2.push_back(res);
//                 }     
//             }
//             else if(ch == '[')
//             {
//                 st2.push_back("[");
//             }
//             else
//             {
//                 string s1(1, ch);
//                 st2.push_back(s1);
//                 last_num = false;
//             }
//         }

//         string result= "";
//         for(auto str: st2)
//         {
//             result+=str;
//         }

//         return result;
//     }
// };