class Solution {
public:
    // quick   select using partition algo of quick sort
    int partition(vector<vector<int>>& points, int left, int right) {

        long long pivotDist = distance(points[right]);
        int pivotIndex = left;

        for(int i = left; i < right; i++) {

            if(distance(points[i]) <= pivotDist) {
                swap(points[i], points[pivotIndex]);
                pivotIndex++;
            }
        }

        swap(points[pivotIndex], points[right]);

        return pivotIndex;
    }

    long long distance(vector<int>& point) {
        long long x = point[0];
        long long y = point[1];

        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int left = 0;
        int right = points.size() - 1;

        while(true) 
        {
            int pivot = partition(points, left, right);

            if(pivot == k - 1) 
            {
                break;
            }
            else if(pivot < k - 1) 
            {
                left = pivot + 1;
            }
            else 
            {
                right = pivot - 1;
            }
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    // heap soln
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
    //     // priority_queue<pair<float,int>> distances;
    //     priority_queue<pair<long long,int>> distances;

    //     int n = points.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         long long dist = 1LL* points[i][0]*points[i][0]+ 1ll* points[i][1]*points[i][1];
    //         // float dist = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
    //         // if sqrt(x)<sqrt(y) -> x < y 
    //         // which leads to avoid floating point calc and precision issues
    //         distances.push({dist,i});
    //         if(distances.size()>k)
    //         {
    //             distances.pop();
    //         }
    //     }

    //     vector<vector<int>> res;
    //     while (!distances.empty()) 
    //     {
    //         res.push_back(points[distances.top().second]);
    //         distances.pop();
    //     }

    //     return res;
    // }
};
