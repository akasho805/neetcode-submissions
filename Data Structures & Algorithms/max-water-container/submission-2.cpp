class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int left = 0;
        int right = heights.size() -1;

        int max_water = 0;

        while(left<right)
        {
            int water,bar;
            if(heights[left]<=heights[right])
            {
                bar = heights[left];
                water = bar * (right-left);
                left++;
            }
            else
            {
                bar = heights[right];
                water = bar * (right-left);
                
                right--;
            }

            max_water = max(water,max_water);
    
        }

        return max_water;
    }
};
