class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char,int> freq;

        for(char ch: s)
        {
            freq[ch]++;
        }

        priority_queue<pair<int,char>> maxH;

        for(auto x: freq)
        {
            maxH.push({x.second,x.first});
        }

        string res = "";
        pair<int,char> temp;

        bool flag = false;

        while(!maxH.empty())
        {
            auto el = maxH.top(); maxH.pop();
            res+=el.second;

            if(flag)
            {
                maxH.push(temp);
            }

            if(el.first-1 !=0)
            {
                temp = {el.first-1,el.second};    
                flag =true;
            }
            else
            {
                flag = false;
            }
        }

        if(res.length()!=s.length())
        {
            return "";
        }

        return res;

    }
};