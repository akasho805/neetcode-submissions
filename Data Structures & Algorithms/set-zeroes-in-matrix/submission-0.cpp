class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size(),cols=matrix[0].size();
        bool colflag=false,rowflag=false;

        //check 1st col
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]==0)
            {
                colflag=true;
            }
        }

        //check 1st row
        for(int j=0;j<cols;j++)
        {
            if(matrix[0][j]==0)
            {
                rowflag=true;
            }
        }

        //mark based on inner matrix
        for(int i = 1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        //update inner matrix
        for(int i = 1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(colflag)
        {
            for(int i=0;i<rows;i++)
            {
                matrix[i][0]=0;
            }
        }

        if(rowflag)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[0][j]=0;
            }
        }

    }
};
