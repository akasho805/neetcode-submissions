class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                return true;
            }
                

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) 
            {
                low++;
                high--;
            
            }
            // Left half is sorted
            else if(nums[low] <= nums[mid])
            {
                //check if target lies in range low to mid
                if(target >= nums[low] && target < nums[mid]) 
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else
            {
                //check if target lies in range mid+1 to high
                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};