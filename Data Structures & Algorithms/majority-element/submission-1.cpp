class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major_el = nums[0];
        int freq = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==major_el)
            {
                freq++;
            }
            else
            {
                freq--;
            }
            if(freq==0)
            {
                major_el=nums[i];
                freq=1;
            }
        }
        return major_el;
    }
};