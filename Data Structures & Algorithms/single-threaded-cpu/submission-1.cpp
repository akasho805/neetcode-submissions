class Solution {
public:
    

    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        priority_queue<pair<pair<int,int>, int>,   vector<pair<pair<int,int>, int>>, 
        greater<pair<pair<int,int>, int>>> q1;
        
        // Comparator function
        auto cmp = [](const auto& a, const auto& b) 
        {
            if(a.first.second == b.first.second)
                return a.second > b.second;

            return a.first.second > b.first.second;
        };

        priority_queue<pair<pair<int,int>, int>,   vector<pair<pair<int,int>, int>>, 
        decltype(cmp)> q2(cmp);

        for(int i=0;i<n;i++)
        {
            q1.push({{tasks[i][0],tasks[i][1]},i});
        }

        int time = 0 ;
        vector<int> res;

        while(!q1.empty() or !q2.empty())
        {
            while(!q1.empty() and time >= q1.top().first.first)
            {
                auto el = q1.top(); q1.pop();
                q2.push(el);
            }

            if (q2.empty()) {
                time = q1.top().first.first;
                continue;
            }

            auto x = q2.top();
            q2.pop();
            time+=x.first.second;
            res.push_back(x.second);

        }

        return res;

    }
};