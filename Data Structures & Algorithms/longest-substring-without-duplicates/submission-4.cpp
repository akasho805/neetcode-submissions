class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left= 0,right=1,n =s.length();

        if(n == left || n == right)
        {
            return n;
        }

        int maxLen=0;
        unordered_set<char> mySet;
        mySet.insert(s[0]);

        while(right<n)
        {
            while(right<n and mySet.count(s[right])==0)
            {
                mySet.insert(s[right]);
                right++;
            }

            maxLen = max(maxLen,(int)mySet.size());

            if(right<n)
            {
                while(mySet.count(s[right])==1)
                {
                    mySet.erase(s[left]);
                    left++;
                } 
            }
        }

        return maxLen;
        
    }
};
