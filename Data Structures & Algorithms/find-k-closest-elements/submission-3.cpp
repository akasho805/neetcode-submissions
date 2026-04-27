class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0, right = arr.size() - k;


        while(left < right) 
        {
            int mid = (left + right) / 2;
    
            if(x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);

        // o(n) soln
        // int left = 0;
        // int right =k;

        // int n = arr.size();
        // while(right<n)
        // {
        //     if(arr[right]-x < x-arr[left]) //Is right side closer than left side?
        //     {
        //         left++;
        //         right++;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }

        // return vector<int>(arr.begin() + left, arr.begin() + right);
    }
};