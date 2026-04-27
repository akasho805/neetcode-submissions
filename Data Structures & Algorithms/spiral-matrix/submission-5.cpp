class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res(rows*cols);
        int k=0;

        int left=0,right=cols-1,top=0,bottom=rows-1;

        while(top<=bottom and left<=right)
        {
            //move left to right
            int i=top,j=left;

            while(j<=right)
            {
                res[k++]=matrix[i][j];
                j++;
            }

            top++;

            //move top to bottom
            i=top;j=right;
            while(i<=bottom)
            {
                res[k++]=matrix[i][j];
                i++;
            }

            right--;

            if(top<=bottom)
            {
                i=bottom;j=right;
                //move right to left
                while(j>=left)
                {
                    res[k++]=matrix[i][j];
                    j--;
                }

                bottom--;
            }
            
            if(left<=right)
            {
                i=bottom;j=left;
                //move bottom to top
                while(i>=top)
                {
                    res[k++]=matrix[i][j];
                    i--;
                }

                left++;
            }

            
        }
        
        return res;
    }
};
