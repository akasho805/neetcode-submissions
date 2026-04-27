class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;

        for(int i=0;i<n-2;i++)
        {
            // since the array is sorted, if nums[i] is already greater then 0 then ,
            // no 2 next +ve int can make the total sum 0
            if(nums[i]>0)
            {
                break;
            }

            // skip duplicates of nums[i] value
            if(i > 0 && nums[i] == nums[i-1]) continue; 

            int j = i +1, k = n-1;
            int need = - nums[i];
            while(j<k)
            {
                int sum = nums[j] + nums[k];
                if(need == sum)
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    // skip duplicates of nums[j] value
                    while(j < k && nums[j] == nums[j+1])
                    {
                        j++;
                    }

                    // skip duplicates of nums[k] value
                    while(j < k && nums[k] == nums[k-1])
                    {
                        k--;
                    }
                    // since nums[j] and nums[k] are add, inc them
                    j++;
                    k--;
                }
                else if ( need > sum)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return res;
    }
};
