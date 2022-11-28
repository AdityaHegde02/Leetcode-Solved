class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        
        int n = matches.size();
        
        map<int,int> left;
        map<int,int> right;
        
        for(int i = 0 ; i < n ; i++){
            left[matches[i][0]]++;
        }
        for(int i = 0 ; i < n ; i++){
            right[matches[i][1]]++;
        }
        
        for(auto i:left){
            if( right.find(i.first)==right.end() ){
                ans[0].push_back(i.first);
            }
        }
        
        for(auto i:right){
            if( i.second==1 ){
                ans[1].push_back(i.first);
            }
        }
        
        return ans;
    }
};