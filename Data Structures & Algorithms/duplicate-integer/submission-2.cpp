class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for(auto x:nums)
        {
            if(mySet.count(x))
            {
                return true;
            }
            mySet.insert(x);
        }

        return false;
    }
    
};