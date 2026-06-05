class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int n =cost.size();
        vector<int> sum(n);

        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            sum[i] = gas[i]-cost[i];
            totalSum+=sum[i];
        }

        if(totalSum<0)
        {
            return -1;
        }

        int i=0;
        int currSum =0;
        int maxI =0;

        while(i<n)
        {
            currSum += sum[i];
            if(currSum < 0)
            {
                currSum = 0;
                maxI=i+1; 
            }
            i++;
        }

        return maxI;

    }
};
