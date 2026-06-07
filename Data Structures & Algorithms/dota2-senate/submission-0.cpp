class Solution {
public:
    string predictPartyVictory(string senate) {
        int n =senate.length();
        queue<int> q1,q2;

        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
            {
                q1.push(i);
            }
            else
            {
                q2.push(i);
            }
        }

        int i =0;
        while(!q1.empty() and !q2.empty())
        {
            if(senate[i]=='R' and q1.front()==i)
            {
                q2.pop();
                int el= q1.front();
                q1.pop();
                q1.push(el);
            }
            else if(senate[i]=='D' and q2.front()==i)
            {
                q1.pop();
                int el= q2.front();
                q2.pop();
                q2.push(el);
            }
            i++;
            i=i%n;
        }

        return (!q1.empty()) ? "Radiant" : "Dire";
    }
};