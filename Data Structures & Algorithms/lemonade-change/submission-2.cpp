class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();
        int avail[3] = {0,0,0};

        for(int i=0;i<n;i++)
        {
            switch(bills[i])
            {
                case 5:
                    ++avail[0];break;
                case 10:
                    ++avail[1];--avail[0];break;
                case 20:
                // if 10 is not avail
                    if(avail[1]==0)
                    {
                        //remove 3 5 dollars
                        ++avail[2];avail[0]-=3;
                    }
                    else
                    {
                        ++avail[2];--avail[0];--avail[1];
                    }
                    break;
            }
            for(int j=0;j<3;j++)
            {
                if(avail[j]<0)
                {
                    return false;
                }
            }
        }

        return true;


    }
};