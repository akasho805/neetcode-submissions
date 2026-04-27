class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size() -1;

        int max_water = INT_MIN;

        while(left<right)
        {
            if(heights[left]<=heights[right])
            {
                int bar = heights[left];
                int water = bar * (right-left);
                max_water = max(water,max_water);
                left++;
            }
            else
            {
                int bar = heights[right];
                int water = bar * (right-left);
                max_water = max(water,max_water);
                right--;
            }
        }

        return max_water;
    }
};
