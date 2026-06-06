class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.length();
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
        }

        return false;
    }
};