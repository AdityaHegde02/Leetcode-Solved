class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int val=1;
        
        vector<vector<int>> ans(n,vector<int> (n,0));
        
        while(top<=bottom and left<=right){
            
            for(int c=left;c<=right;c++){
               ans[top][c]=val;
               val++;
            }
            
            for(int r=top+1;r<=right;r++){
               ans[r][right]=val;
               val++;
            }
            
            if(top<bottom and left<right){
                
                for(int c=right-1;c>=left;c--){
                     ans[bottom][c]=val;
                     val++;
                 }
                 for(int r=bottom-1;r>top;r--){
                     ans[r][left]=val;
                     val++;
                 }
            }

            top++;
            bottom--;
            left++;
            right--;
        }
        return ans;
    }
};