class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }

        int idx=0,len=strs.size(),i,j;
        string temp = strs[0];
        idx=temp.length();
        for(i =1;i<len;i++)
        {
            for(j=0;j<strs[i].length() and j<temp.length() and j<idx;j++)
            {
                if(temp[j]!=strs[i][j])
                {
                    break;
                }
            }
            idx=j;
        }

        // | Approach                                  | Time Complexity      | Space Complexity | Notes                                        |
        // | ----------------------------------------- | -------------------- | ---------------- | -------------------------------------------- |
        // | **Your solution (progressive shrinking)** | **O(n × m)**         | **O(1)**         | Optimal, safest, preferred in interviews     |
        // | **Vertical scan**                         | **O(n × m)**         | **O(1)**         | Cleanest logic, very interview-friendly      |
        // | **Binary search on prefix length**        | **O(n × m × log m)** | **O(1)**         | Extra log factor, rarely preferred           |
        // | **Trie-based**                            | **O(L)**             | **O(L)**         | High memory usage, overkill for single query |
        // | **Sort + first & last**                   | **O(n log n × m)**   | **O(1)**         | Clever trick, worse asymptotically           |

        return temp.substr(0, idx);
    }
};