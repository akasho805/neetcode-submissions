class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i =1;i<=n;i++)
        {
            res[i]=hammingWeight(i);
        }

        return res;
    }
};
