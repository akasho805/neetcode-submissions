class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left= 0,right=0,n =s.length();

        int maxLen=0;
        while(left<n)
        {
            set<int> mySet;

            //insert 1st el of window
            if(left == right)
            {
                mySet.insert(s[right]);
                right++;
            }

            while(right<n and mySet.count(s[right])==0)
            {
                mySet.insert(s[right]);
                right++;
            }

            maxLen = max(maxLen,(int)mySet.size());
            left++;
            right=left;
        }

        return maxLen;
        
    }
};
