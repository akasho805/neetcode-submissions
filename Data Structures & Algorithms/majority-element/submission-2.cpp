class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major_el ;
        int freq = 0;
        for(int i=0;i<n;i++)
        {
            if(freq==0)
            {
                major_el=nums[i];
            }
            freq+= (nums[i]==major_el) ? 1 : -1;    
        }
        return major_el;
    }
};