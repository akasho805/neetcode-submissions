class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.length();

        // not needed due to this problme constraints
        // if(s[0]==1)
        // {
        //     return false;
        // }

        queue<int> q;
        q.push(0);
        int maxIdx = 0;

        while(!q.empty())
        {
            int el = q.front();
            q.pop();

            for(int i = max(el + minJump, maxIdx + 1); i < min(n,el + maxJump + 1); i++)
            {
                if(s[i]=='0')
                {
                    q.push(i);
                    if(i==n-1)
                    {
                        return true;
                    }
                }
            }
            maxIdx = el + maxJump;
            // maxIdx = max(maxIdx,el + maxJump); also can be used for stricter
        }

        return false;
    }
};