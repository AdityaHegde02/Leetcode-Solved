class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,r=m-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(mat[mid][n-1]<target){
                l=mid+1;
            }
            else if(mat[mid][0]>target){
                r=mid-1;
            }
            else{
                l=mid;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[l][i]==target){
                return true;
            }
        }
        return false;
    }
};