class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int row = 0 ; row < n ; row++){             // transpose
            for(int column = row+1 ; column < n ; column++){
                swap( matrix[row][column] , matrix[column][row] );
            } 
        }
        
        for(int column = 0 ; column < n/2 ;column++){   //reverse
            for(int row = 0 ;row < n ;row++){
                swap( matrix[row][column] , matrix[row][n-1-column] );
            }
        }
    }
};