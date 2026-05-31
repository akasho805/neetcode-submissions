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
                if(nums[left]+left > maxReach)
                {
                    // left = right +1;
                    // right = left + nums[left];
                    // jumps++;
                    maxReach = nums[left]+left;
                }
                left++;
            }
            right = maxReach;
            jumps++; 
        }

        return jumps;
    }
};
