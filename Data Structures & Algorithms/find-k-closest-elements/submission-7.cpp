class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0, right = arr.size() - k;

        //find the left of window
        while(left < right) 
        {
            int mid = left + (right - left) / 2;

            //Is the left boundary worse than the right boundary
            // Why no abs() is needed?
            // Since arr is sorted, arr[mid] ≤ arr[mid+k], so distances can be compared without absolute values.
            if(x - arr[mid] > arr[mid + k] - x) 
            {
                // yes → shift window right
                left = mid + 1;
            }
            else
            {
                // Else → keep or move left
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
  
    }
};