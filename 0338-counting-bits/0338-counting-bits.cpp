class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int j=i;
            int count=0;
            while(j!=0){
                j=j & (j-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};