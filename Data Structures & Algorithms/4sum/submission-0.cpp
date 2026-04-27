class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < n - 3; i++)
        {
            // since the array is sorted, if nums[i] is already greater then 0 then ,
            // no 2 next +ve int can make the total sum 0
            if(nums[i]>target)
            {
                break;
            }
            
            // skip duplicates of nums[i] value
            if(i > 0 && nums[i] == nums[i-1]) continue; 

            for(int j = i + 1; j < n - 2; j++)
            {
                // skip duplicates for j
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1, right = n - 1;

                long long need = (long long)target - nums[i] - nums[j];

                while(left < right)
                {
                    long long sum = nums[left] + nums[right];

                    if(sum == need)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // skip duplicates of left
                        while(left < right && nums[left] == nums[left+1])
                        {
                            left++;
                        }

                        // skip duplicates of right
                        while(left < right && nums[right] == nums[right-1])
                        {
                            right--;
                        }

                        left++;
                        right--;
                    }
                    else if(sum < need)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};