class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int prev = 0;

        for(int curr = 0; curr < nums.size(); curr++)
        {
            if(nums[curr] != val)
            {
                nums[prev++] = nums[curr];
            }
        }

        return prev;
    }    
};