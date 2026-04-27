class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int mx=INT_MIN;
        for(int x:piles)
        {
            mx = max(mx,x);
        }

        int left = 1;
        //do not use left = sum/h as this agressive guessing does not work when work is unevenly distributed
        int right = mx;

        while(left<=right)
        {
            int mid =(left+right)/2;
            int hours =0 ;
            for(int i=0;i<piles.size();i++)
            {
                hours +=(piles[i]+mid-1)/mid; //calc ceil using integers
            }
            if(hours<=h)
            {
                right=mid-1;
            }
            else 
            {
                left=mid+1;
            }
        }
        return left;


    }
};
