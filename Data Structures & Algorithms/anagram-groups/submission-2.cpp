class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(string &s : strs)
        {
            vector<int> freq(26, 0);

            for(char c : s)
            {
                freq[c - 'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++)
            {
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &p : mp)
        {
            result.push_back(p.second);
        }

        return result;
        //naive soln of sort and mapping
        // unordered_map<string, vector<string>> mp;

        // for(string &s : strs)
        // {
        //     string key = s;
        //     sort(key.begin(), key.end());  // create signature
            
        //     mp[key].push_back(s);
        // }

        // vector<vector<string>> result;
        // for(auto &p : mp)
        // {
        //     result.push_back(p.second);
        // }

        // return result;
    }
};


