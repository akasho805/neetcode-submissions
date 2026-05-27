class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int i = 0;
        int n = intervals.size();

        vector<vector<int>> res;
        // intervals completely before newInterval
        while(i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0],intervals[i][0]);

            newInterval[1] = max(newInterval[1],intervals[i][1]);

            i++;
        }

        // add merged interval
        res.push_back(newInterval);

        // remaining intervals
        while(i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
        // search pos to insert and merge intervals
        // //search index to insert
        // int low = 0,high = n-1;
        // int idx = -1;
        // while(low<=high)
        // {
        //     int mid = low + (high-low)/2;
        //     if(newInterval[0] == intervals[mid][0])
        //     {
        //         //insert
        //         intervals.insert(intervals.begin() + mid, newInterval);
        //         idx = mid;
        //         break;
        //     }
        //     else if(newInterval[0] > intervals[mid][0])        
        //     {
        //         low=mid+1;
        //     }
        //     else
        //     {
        //         high =mid-1;
        //     }
        // }

        // if(low>high)
        // {
        //     intervals.insert(intervals.begin() + low, newInterval);
        //     idx = low;
        // }


        // vector<vector<int>> res;
        // n++;

        // int i =0;
        // while(i < n)
        // {
        //     int start = intervals[i][0],end = intervals[i][1];
        //     while(i<n-1 && end >=intervals[i+1][0])
        //     {
        //         end = max(end, intervals[i+1][1]);
        //         i++;
        //     }
        //     res.push_back({start,end});
        //     i++;
        // }

        // return res;

    }
};
