
class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,vector<int> &temp,vector<int> &nums){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //notake
        solve(i + 1,temp,nums);
        
        //take
        temp.push_back(nums[i]);
        solve(i + 1,temp,nums);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0,temp,nums);
        return ans;
    }
};