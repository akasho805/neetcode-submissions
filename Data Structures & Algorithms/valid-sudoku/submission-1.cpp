class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowMap(9),colMap(9),boxMap(9);

        int rows = 9,cols = 9;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                char curr = board[i][j];
                if(curr == '.')
                {
                    continue;
                }

                auto &it1 = rowMap[i];
                auto &it2 = colMap[j];

                //calc which box the curr el belongs
                int idx = 3*(i/3) + j/3;

                auto &it3 = boxMap[idx];
                if(it1.count(curr) == 1 || it2.count(curr) == 1 || it3.count(curr) == 1)
                {
                    return false;
                }
                else
                {
                    it1.insert(curr);
                    it2.insert(curr);
                    it3.insert(curr);
                }
            }
        }

        return true;

    }
};
