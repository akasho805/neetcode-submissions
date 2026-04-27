class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < n - 3; i++)
        {
            //early pruning
            if((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if((long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            // skip duplicates of nums[i] value
            if(i > 0 && nums[i] == nums[i-1]) continue; 

            for(int j = i + 1; j < n - 2; j++)
            {
                //early pruning
                if((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;

                // skip duplicates for j
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1, right = n - 1;

                long long need = (long long)target - nums[i] - nums[j];

                while(left < right)
                {
                    long long sum = (long long)nums[left] + nums[right];

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