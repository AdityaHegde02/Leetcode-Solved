class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& d) {
        int mx = 0,ans = INT_MAX;
        vector<int> temp;
        for(int i = 0; i < d.size(); ++i){
            int curr = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(nums[j] % d[i] == 0){
                    curr++;
                }
            }
            temp.push_back(curr);
        }
        for(int i = 0; i < d.size();i++){
            mx = max(mx,temp[i]);
        }
        
        for(int i = 0; i < d.size(); i++){
            if(temp[i] == mx){
                ans = min(ans,d[i]);
            }
        }
        return ans;
    }
};