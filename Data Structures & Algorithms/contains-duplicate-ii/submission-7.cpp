class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // Time  : O(n)
    // Space : O(k)
    unordered_set<int> window;

    for(int i = 0; i < nums.size(); i++)
    {
        if(window.count(nums[i]))
            return true;

        window.insert(nums[i]);

        if(window.size() > k) 
            window.erase(nums[i-k]); //remove the 1st element of window to move thw window ahead by one
            //this ensures the curr elemnt is checked for the last k window elements only
    }

    return false;


        // brute force
        // int n =nums.size();
        // for(int i =0;i<n;i++)
        // {
        //     for(int j=i+1;j<n&& j-i<=k;j++)
        //     {
        //         if(nums[i]==nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

    }
};