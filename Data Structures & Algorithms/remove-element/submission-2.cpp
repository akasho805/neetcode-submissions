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
    // order not preserved but lesser swaps
    // int left = 0;
    // int right = nums.size();

    // while (left < right) {
    //     if (nums[left] == val) 
    //     {
    //         nums[left] = nums[right - 1];
    //         right--;
    //     } 
    //     else 
    //     {
    //         left++;
    //     }
    // }
    // return right;
};