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
            //move left to right (top-left)
            for (int j = left; j <= right; j++)
            {
                res[k++]=matrix[top][j];
            }
            top++;

            //move top to bottom (top-right)
            for (int i = top; i <= bottom; i++)
            {
                res[k++]=matrix[i][right];
            }
            right--;

            if(top<=bottom)
            {
                //move right to left (bottom-right)
                for (int j = right; j >= left; j--)
                {
                    res[k++]=matrix[bottom][j];
                }
                bottom--;
            }
            
            if(left<=right)
            {
                //move bottom to top (bottom-left)
                for (int i = bottom; i >= top; i--)
                {
                    res[k++]=matrix[i][left];
                }
                left++;
            }
  
        }
        
        return res;
    }
};
