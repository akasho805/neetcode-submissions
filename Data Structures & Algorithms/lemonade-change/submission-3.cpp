class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();
        int fives = 0, tens =0;

        for(int i=0;i<n;i++)
        {
            switch(bills[i])
            {
                case 5:
                    ++fives;break;
                case 10:
                    ++tens;--fives;break;
                case 20:
                // if 10 is not avail
                    if(tens==0)
                    {
                        //remove 3 5 dollars
                        fives-=3;
                    }
                    else
                    {
                        --fives;--tens;
                    }
                    break;
            }
            if(fives<0 || tens<0)
            {
                return false;
            }
        }

        return true;


    }
};