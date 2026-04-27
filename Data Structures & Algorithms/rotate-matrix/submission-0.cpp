class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>> result(cols, vector<int> (rows, 0));

        for(int i = 0;i<rows;i++)
        {
            for(int j =0 ; j<cols;j++)
            {
                result[j][i]=matrix[i][j];
            }
        }

        return result;
    }

    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        //swap row 1 with last row, 2nd with 2nd last and so on
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n;j++)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }

        matrix=transpose(matrix);

    }
};
