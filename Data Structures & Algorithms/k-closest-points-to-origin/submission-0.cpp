class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<float,int>> distances;

        int n = points.size();

        for(int i=0;i<n;i++)
        {
            float dist = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            distances.push({dist,i});
            if(distances.size()>k)
            {
                distances.pop();
            }
        }

        vector<vector<int>> res;
        while (!distances.empty()) 
        {
            res.push_back(points[distances.top().second]);
            distances.pop();
        }

        return res;
    }
};
