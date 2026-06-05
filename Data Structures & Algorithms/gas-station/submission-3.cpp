class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int n =cost.size();
        int totalSum = 0;
        int currSum =0;
        int maxI =0;

        for(int i=0;i<n;i++)
        {
            int diff = gas[i]-cost[i];
            currSum += diff;
            totalSum += diff;

            if(currSum < 0)
            {
                currSum = 0;
                maxI=i+1; 
            }
        }

        return (totalSum<0) ? -1 : maxI ;

    }
};
