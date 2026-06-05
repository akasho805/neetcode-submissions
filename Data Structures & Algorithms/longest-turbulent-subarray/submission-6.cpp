class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();

        int prev = 0; //0 => = , 1 => < , -1 => > 

        int left = 0,right = 1,maxLen=1;

        while(right<n)
        {
            if(arr[right-1] < arr[right] and prev != 1)
            {
                maxLen = max(right-left+1,maxLen);
                prev = 1;right++;

            }
            else if(arr[right-1] > arr[right] and prev != -1)
            {
                maxLen = max(right-left+1,maxLen);
                prev = -1;right++;
            }
            else // 2 conssecutivce < or > or = encountered
            {
                prev = 0;
                right = (arr[right] == arr[right-1]) ? right + 1 : right;
                left = right-1;
            }  
        }
        
        return maxLen;
    }
};