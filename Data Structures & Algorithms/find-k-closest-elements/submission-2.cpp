class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0;
        int right =k;

        int n = arr.size();
        while(right<n)
        {
            if(arr[right]-x < x-arr[left]) //Is right side closer than left side?
            {
                left++;
                right++;
            }
            else
            {
                break;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + right);
    }
};