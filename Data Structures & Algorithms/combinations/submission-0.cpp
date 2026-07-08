class Solution {
public:

    void dfs(int i,int n,int k,vector<int>& combo,vector<vector<int>>& res)
    {
        //base case1
        if(combo.size()==k)
        {
            res.push_back(combo);
            return;
        }

        //base case2
        if(i>n)
        {
            return;
        }
        
        combo.push_back(i);
        dfs(i+1,n,k,combo,res);
        combo.pop_back();
        dfs(i+1,n,k,combo,res);
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<int> combo;
        vector<vector<int>> res;

        dfs(1,n,k,combo,res);

        return res;
    }
};