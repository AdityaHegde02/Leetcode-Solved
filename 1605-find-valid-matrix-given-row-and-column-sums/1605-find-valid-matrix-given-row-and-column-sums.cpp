class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int m=r.size(),n=c.size();
        int mn=INT_MAX;
        vector<vector<int>> ans(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(r[i]<=c[j]){
                    ans[i][j]=r[i];
                    r[i]=0;
                    c[j]-=ans[i][j];
                }
                else{
                    ans[i][j]=c[j];
                    c[j]=0;
                    r[i]-=ans[i][j];
                }
            }
        }
        return ans;
    }
};