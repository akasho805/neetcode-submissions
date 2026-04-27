class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> mySet;
        int maxLen = 0;

        for(int x: nums)
        {
            mySet.insert(x);
        }

        for(auto x:mySet)
        {
            int temp = x;
            if(mySet.count(temp-1) != 1)
            {
                int len = 0;
                while(mySet.count(temp) == 1)
                {
                    len++;
                    // mySet.erase(temp);
                    temp++;
                }
                maxLen= max(maxLen,len);
            }
            // else
            // {
            //     mySet.erase(x);
            // }
        }

        return maxLen;
    }
};
