class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char,int> freq;

        for(char ch: s)
        {
            freq[ch]++;
        }

        priority_queue<pair<int,char>> maxHeap;

        for(auto x: freq)
        {
            maxHeap.push({x.second,x.first});
        }

        //early exit
        int n = s.length();
        int maxFreq = maxHeap.top().first;
        if(maxFreq > (n+1)/2)
        {
            return "";
        }

        pair<int,char> prev = {0,'#'};
        string res = "";
        bool flag = false;

        while(!maxHeap.empty())
        {
            auto curr = maxHeap.top(); maxHeap.pop();
            res+=curr.second;

            if(flag)
            {
                maxHeap.push(prev);
            }

            if(curr.first-1 !=0)
            {
                prev = {curr.first-1,curr.second};    
                flag =true;
            }
            else
            {
                flag = false;
            }
        }

        return  res;

    }
};