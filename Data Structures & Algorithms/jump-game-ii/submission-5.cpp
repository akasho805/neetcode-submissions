class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n =nums.size();
        int jumps = 0;
        int left = 0,right = 0,maxReach = 0;

        while(right<n-1)
        {
            while(left<=right)
            {
                // if(nums[left]+left > maxReach)
                // {
                //     maxReach = nums[left]+left;
                // }
                maxReach = max(maxReach,nums[left]+left);
                left++;
            }
            right = maxReach;
            jumps++; 
        }

        return jumps;
    }
};
