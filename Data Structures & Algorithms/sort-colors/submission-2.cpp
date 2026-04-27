class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero =0,one =0,two=nums.size()-1;

        while(one<=two)
        {
            if(nums[one] == 0)
            {
                swap(nums[zero],nums[one]);
                zero++;one++;
            }
            else if(nums[one] == 1)
            {
                
                one++;
            }
            else
            {
                swap(nums[two],nums[one]);
                two--;
            }
        }

        // count method
        // int count_2 = 0 ,count_1 = 0, count_0 = 0;

        // for(int x: nums)
        // {
        //     if(x == 0)
        //     {
        //         count_0++;
        //     }
        //     else if(x == 1)
        //     {
        //         count_1++;
        //     }
        //     else
        //     {
        //         count_2++;
        //     }
        // }

        // int i =0;
        // while(count_0)
        // {
        //     nums[i] = 0;
        //     i++;
        //     count_0--;
        // }
        // while(count_1)
        // {
        //     nums[i] = 1;
        //     i++;
        //     count_1--;
        // }
        // while(count_2)
        // {
        //     nums[i] = 2;
        //     i++;
        //     count_2--;
        // }

    }
};