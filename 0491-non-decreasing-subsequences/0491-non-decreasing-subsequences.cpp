class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    
    void solve(int idx,int prev,vector<int> &temp,vector<int> &nums){
        if(idx >= nums.size()){
            if(temp.size() >= 2 and st.find(temp) == st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            return ;
        }
        
        if(nums[idx] >= prev){
            temp.push_back(nums[idx]);
            solve(idx + 1,nums[idx],temp,nums);
            temp.pop_back();
            solve(idx + 1,prev,temp,nums);
        }
        else{
            solve(idx + 1,prev,temp,nums);
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0,-101,temp,nums);
        return ans;    
    }
};