const static auto fast=[]{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=34;
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> a{{1,1}};
        ans.push_back({1,1});
        int row=2;
        for(int i=row;i<numRows;i++){
            a=ans.back();
            int j=0;
            row=i;
            vector<int> b;
            while(j!=row-1){
                if(j==0){
                    b.push_back(a[0]);
                }
                b.push_back(a[j]+a[j+1]);
                if(j==row-2){
                     b.push_back(1);
                     ans.push_back(b);
                }
                j++;
            }
        }
        return ans[rowIndex];
    }
};