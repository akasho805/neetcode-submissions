class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> lastPos;

        int n =s.length();

        for(int i=0;i<n;i++)
        {
            lastPos[s[i]]=i;
        }

        vector<int> res;

        int left =0,right =0 ;

        while(left<n)
        {
            int currLen =0;
            while(left<=right)
            {
                right=max(right,lastPos[s[left]]);
                left++;
                currLen++;
            }
            res.push_back(currLen);
            right++;
        }

        return res;
    }
};
