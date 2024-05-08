class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& a) {
        vector<pair<int,int>> pos;
        vector<string> ans(a.size());
        for(int i=0;i<a.size();i++){
            pos.push_back({a[i],i});
        }
        sort(pos.rbegin(),pos.rend());
        int count=0;
        for(int i=0;i<pos.size();i++){
            if(i==0){
                ans[pos[0].second]="Gold Medal";
            }
            else if(i==1){
                ans[pos[1].second]="Silver Medal";
            }
            else if(i==2){
                ans[pos[2].second]="Bronze Medal";
            }
            else{
                ans[pos[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
};