class Solution {
public:

    int partition(int left,int right, vector<int> &nums)
    {
        int pivot = right;
        for(int i =right;i>=left;i--)
        {
            if(nums[i]>=nums[pivot])
            {
                swap(nums[i],nums[right]);
                right--;
            }
        }
        swap(nums[right+1],nums[pivot]);
        return right+1;
    }

    int findKthLargest(vector<int>& nums, int k) {

        int left = 0,right = nums.size()-1;

        while(true)
        {
            int pivot = partition(left,right,nums);

            if(pivot == nums.size()-k)
            {
                return nums[pivot];
            }
            else if(pivot < nums.size()-k)
            {
                left = pivot+1;
            }
            else
            {
                right = pivot-1;
            }
        }


        // heap soln
        // priority_queue<int,vector<int>,greater<int>> minH;

        // for(int x: nums)
        // {
        //     minH.push(x);
        //     if(minH.size()>k)
        //     {
        //         minH.pop();
        //     }
        // }

        // return minH.top();
    }
};
