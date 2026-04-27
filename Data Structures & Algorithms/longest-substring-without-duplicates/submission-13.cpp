class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // chatgpt code
        unordered_map<char, int> lastSeen;
        int left = 0, maxLen = 0, n = s.length();

        for(int right = 0; right < n; right++) {
            if(lastSeen.count(s[right])) {
                left = max(left, lastSeen[s[right]] + 1);
            }

            lastSeen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        // return maxLen;

        // good, but can be improved like above
        // int left= 0,right=0,n =s.length();
        // int maxLen=0;
        // unordered_set<char> mySet;

        // while(right<n)
        // {
        //     //while duplicate exists shrink
        //     while(mySet.count(s[right])==1)
        //     {
        //         mySet.erase(s[left]);
        //         left++;
        //     }
        //     mySet.insert(s[right]);
        //     right++;
        //     maxLen = max(maxLen,(int)mySet.size());
        // }

        //cleaner way writtern above
        // while(right<n)
        // {
        //     while(right<n and mySet.count(s[right])==0)
        //     {
        //         mySet.insert(s[right]);
        //         right++;
        //     }

        //     maxLen = max(maxLen,(int)mySet.size());

        //     if(right<n)
        //     {
        //         while(mySet.count(s[right])==1)
        //         {
        //             mySet.erase(s[left]);
        //             left++;
        //         } 
        //     }
        // }

        return maxLen;
        
    }
};
