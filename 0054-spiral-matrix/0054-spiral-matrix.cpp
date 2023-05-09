class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row_start=0,row_end=m-1;
        int column_start=0,column_end=n-1;
        vector<int> ans;

        // until this condition we move on
        while(row_start<=row_end and column_start<=column_end){

            // for left to right print
            for (int i =column_start;i<=column_end;i++){
                ans.push_back(matrix[row_start][i]);
            }
        
            row_start++;

            // for top to bottom print
            for (int i= row_start; i<= row_end;i++)
            {
                ans.push_back(matrix[i][column_end]);
            }
            
            column_end--;

            if(row_start<=row_end)
            // for right to left print
                for (int i =column_end ;i>= column_start; i--)
                {
                    ans.push_back(matrix[row_end][i]); 
                }
        
                row_end--;

            if(column_start<=column_end)
            // for bottom to top print
                for (int j= row_end; j >= row_start; j--)
                {
                    ans.push_back(matrix[j][column_start]);
                }
                column_start++;
            }
        return ans;
    }
};