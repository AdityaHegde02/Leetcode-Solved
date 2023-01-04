class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,int k,int sum,vector<int> &temp){
        if(temp.size() == k and sum == 0){
            ans.push_back(temp);
            return ;
        }
        
        if(i > 9){
            return ;
        }
    
        if(i <= sum){
            temp.push_back(i);
            solve(i + 1,k,sum - i,temp);
            temp.pop_back();
        }
    
        solve(i + 1,k,sum,temp);
    }
    
    vector<vector<int>> combinationSum3(int k, int sum) {
        if(sum > 45){
            return {};
        }
        vector<int> temp;
        int i = 1;
        solve(i,k,sum,temp);
        return ans;
    }
};