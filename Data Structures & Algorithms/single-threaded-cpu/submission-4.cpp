class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // using 1 sort + 1 minHeap
        int n = tasks.size();

        vector<array<long long,3>> t;

        for(int i = 0; i < n; i++) {
            t.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(t.begin(), t.end());

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<int> res;

        long long time = 0;
        int i = 0;

        while(i < n || !pq.empty()) {

            if(pq.empty())
                time = max(time, t[i][0]);

            while(i < n && t[i][0] <= time) {
                pq.push({t[i][1], t[i][2]});
                i++;
            }

            auto [process, index] = pq.top();
            pq.pop();

            time += process;

            res.push_back(index);
        }

        return res;
    }
};

// using 2 minHeaps

// class Solution {
// public:
    

//     vector<int> getOrder(vector<vector<int>>& tasks) {

//         int n = tasks.size();

//         priority_queue<pair<pair<int,int>, int>,   vector<pair<pair<int,int>, int>>, 
//         greater<pair<pair<int,int>, int>>> q1;
        
//         // lambda function
//         auto cmp = [](const auto& a, const auto& b) 
//         {
//             if(a.first.second == b.first.second) // if both have same processingTime
//                 return a.second > b.second;     // sort based on smallest index (in custom logic is reversed)

//             return a.first.second > b.first.second; // sort based on processingTime (in custom logic is reversed)
//         };

//         priority_queue<pair<pair<int,int>, int>,   vector<pair<pair<int,int>, int>>, 
//         decltype(cmp)> q2(cmp);

//         for(int i=0;i<n;i++)
//         {
//             q1.push({{tasks[i][0],tasks[i][1]},i});
//         }

//         long long time = 0 ;
//         vector<int> res;

//         while(!q1.empty() or !q2.empty())
//         {
//             while(!q1.empty() and time >= q1.top().first.first)
//             {
//                 auto el = q1.top(); q1.pop();
//                 q2.push(el);
//             }

//             if (q2.empty()) {
//                 time = q1.top().first.first;
//                 continue;
//             }

//             auto x = q2.top();
//             q2.pop();
//             time+=x.first.second;
//             res.push_back(x.second);

//         }

//         return res;

//     }
// };