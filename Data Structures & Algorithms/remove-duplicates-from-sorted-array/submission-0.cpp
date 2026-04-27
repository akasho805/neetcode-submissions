class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0 , curr = 0,n=nums.size(),k=0;

        while(curr<n)
        {
            if(nums[prev] == nums[curr])
            {
                curr++;
            }
            else
            {
                nums[++prev] = nums[curr++];
                k++;
            }
        }
        return k+1;
    }
};