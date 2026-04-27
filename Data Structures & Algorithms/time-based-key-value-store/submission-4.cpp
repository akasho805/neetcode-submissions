class TimeMap {
public:
    TimeMap() {
        
    }

    
    unordered_map<string ,vector<pair<string,int>>> mp;

    void set(string key, string value, int timestamp) {
        
        mp[key].push_back({value,timestamp});

    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end())
            return "";

        auto &vec = mp[key];

        int n = vec.size();
        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int value = vec[mid].second;
            if(value==timestamp)
            {
                return vec[mid].first;
            }
            else if(value > timestamp)
            {
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high >= 0 ? vec[high].first : "";

    }
};
