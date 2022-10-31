class Solution {
public:
    void solve(int i,int n,vector<int> &temp,vector<int> &nums,vector<vector<int>> &ans){
        if(i > n){
            return ;
        }
        
        if(i == n){
            ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[i]);
        solve(i+1,n,temp,nums,ans);
        temp.pop_back();
        solve(i+1,n,temp,nums,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,n,temp,nums,ans);
        set<vector<int>> s;
        for(auto &i:ans){
            s.insert(i);
        }
        ans.clear();
        for(auto &i : s){
            ans.push_back(i);
        }
        return ans;
    }
};