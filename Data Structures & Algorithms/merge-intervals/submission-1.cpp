class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        int n = intervals.size();

        int i =0;

        // int start = intervals[0][0],end = intervals[0][1];

        while(i < n)
        {
            int start = intervals[i][0],end = intervals[i][1];
            while(i<n-1 && end >=intervals[i+1][0])
            {
                if(end <= intervals[i+1][1])
                {
                    end = intervals[i+1][1];
                }
                i++;
            }
            res.push_back({start,end});
            i++;
        }

        return res;
    }
};
