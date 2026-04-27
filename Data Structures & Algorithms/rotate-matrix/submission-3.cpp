class Solution {
public:

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

        for(int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++) //+1 avoids diagonal swpa with itself
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
};
