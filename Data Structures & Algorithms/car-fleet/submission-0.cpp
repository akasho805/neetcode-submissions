class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();

        if(n == 1)
        {
            return 1;
        }

        vector<pair<int,int>> cars;

        for(int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        vector<float> time;

        for(int i = 0; i < n; i++)
        {
            float calc = (target - cars[i].first) * 1.0 / cars[i].second;
            time.push_back(calc);
        }
        
        stack<float> st;
        st.push(time[0]);

        for(int i=1;i<n;i++)
        {
            if(!st.empty() and time[i]>st.top())
            {
                st.push(time[i]);
            }
        }

        return st.size();
    }
};