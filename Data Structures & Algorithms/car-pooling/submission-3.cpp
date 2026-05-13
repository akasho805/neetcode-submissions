class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // constraints say locations are <= 1000 so we can brute force
        vector<int> diff(1001, 0);

        for(auto &trip : trips)
        {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            // passengers enter
            diff[start] += passengers;

            // passengers leave
            diff[end] -= passengers;
        }

        int currPassengers = 0;

        for(int i = 0; i <= 1000; i++)
        {
            currPassengers += diff[i];

            if(currPassengers > capacity)
            {
                return false;
            }
        }

        return true;
        
        // heap based general soln
        // //sort based on pickup time
        // sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
        //     return a[1] < b[1];
        // });

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // [end, numPassengers]
        // int curPass = 0;

        // for (const auto& trip : trips) {
        //     int numPass = trip[0], start = trip[1], end = trip[2];

        //     while (!minHeap.empty() && minHeap.top().first <= start) {
        //         curPass -= minHeap.top().second;
        //         minHeap.pop();
        //     }

        //     curPass += numPass;
        //     if (curPass > capacity) {
        //         return false;
        //     }

        //     minHeap.push({end, numPass});
        // }

        // return true;
    }
};