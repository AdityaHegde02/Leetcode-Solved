class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,vector<int> &temp,int target,vector<int> &can){
        if(i >= can.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return ;
        }
        
        if(target < 0){
            return ;
        }
        
        //take
        temp.push_back(can[i]);
        solve(i + 1,temp,target - can[i],can);
        temp.pop_back();
        
        // not take
        while(i < can.size() - 1 and can[i] == can[i + 1]){
            i++;
        }
        
        solve(i + 1,temp,target,can);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<int> temp;
        sort(can.begin(),can.end());
        solve(0,temp,target,can);
        return ans;
    }
};