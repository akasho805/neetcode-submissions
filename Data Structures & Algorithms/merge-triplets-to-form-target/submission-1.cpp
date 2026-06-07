class Solution {
public:

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int n =triplets.size();

        vector<vector<int>> valid;

        for(int i =0;i<n;i++)
        {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
            {
                valid.push_back(triplets[i]);
            }
        }

        int m = valid.size();

        bool flag[3] = {false,false,false};

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(valid[j][i] == target[i])
                {
                    flag[i]=true;
                }
            }
            if(flag[i]==false)
            {
                return false;
            }
        }

        return true;
    }
};
