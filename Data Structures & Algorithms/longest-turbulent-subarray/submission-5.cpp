class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();

        string prev = "";

        int left = 0,right = 1,maxLen=1;

        while(right<n)
        {
            if(arr[right-1] < arr[right] and prev !="<")
            {
                maxLen = max(right-left+1,maxLen);
                prev = "<";right++;

            }
            else if(arr[right-1] > arr[right] and prev !=">")
            {
                maxLen = max(right-left+1,maxLen);
                prev = ">";right++;
            }
            else // 2 conssecutivce < or > or = encountered
            {
                prev = "";
                right = (arr[right] == arr[right-1]) ? right + 1 : right;
                left = right-1;
            }  
        }
        
        return maxLen;
    }
};