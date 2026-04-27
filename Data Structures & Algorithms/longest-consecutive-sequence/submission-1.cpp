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
            if(mySet.count(x-1) == 0)
            {
                int temp = x;
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
