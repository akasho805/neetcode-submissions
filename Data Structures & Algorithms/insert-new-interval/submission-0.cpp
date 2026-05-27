class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        

        int n = intervals.size();
        //search index to insert
        int low = 0,high = n-1;
        int idx = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(newInterval[0] == intervals[mid][0])
            {
                //insert
                intervals.insert(intervals.begin() + mid, newInterval);
                idx = mid;
                break;
            }
            else if(newInterval[0] > intervals[mid][0])        
            {
                low=mid+1;
            }
            else
            {
                high =mid-1;
            }
        }

        if(low>high)
        {
            intervals.insert(intervals.begin() + low, newInterval);
            idx = low;
        }


        vector<vector<int>> res;
        n++;

        int i =0;
        while(i < n)
        {
            int start = intervals[i][0],end = intervals[i][1];
            while(i<n-1 && end >=intervals[i+1][0])
            {
                end = max(end, intervals[i+1][1]);
                // if(end <= intervals[i+1][1])
                // {
                //     end = intervals[i+1][1];
                // }
                i++;
            }
            res.push_back({start,end});
            i++;
        }

        return res;

    }
};
