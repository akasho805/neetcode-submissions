class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // priority_queue<pair<float,int>> distances;
        priority_queue<pair<long long,int>> distances;

        int n = points.size();

        for(int i=0;i<n;i++)
        {
            long long dist = 1LL* points[i][0]*points[i][0]+ 1ll* points[i][1]*points[i][1];
            // float dist = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            // if sqrt(x)<sqrt(y) -> x < y 
            // which leads to avoid floating point calc and precision issues
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
