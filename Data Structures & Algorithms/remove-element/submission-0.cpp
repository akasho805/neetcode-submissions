class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(!n)
        {
            return 0;
        }

        int prev = 0,curr= 0;

        while(curr<n and prev <n)
        {
            while(nums[prev]!=val and prev < n)
            {
                prev++;
            }
            curr = prev;

            while(nums[curr]==val and curr < n)
            {
                curr++;
            }
            swap(nums[prev++],nums[curr]);
        }
        return prev-1;
    }    
};