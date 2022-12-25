class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(),m = queries.size();
        vector<int> ans(m,0);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < m; i++){
            int x = queries[i];
            int curr = 0;
            if(x < nums[0]){
                ans[i] = 0; 
            }
            for(int j = 0; j < n; j++){
                curr += nums[j];
                if(curr > x){
                    ans[i] = j;
                    break;
                }
                if(j == n - 1){
                    ans[i] = n;
                }
            }
        }
        return ans;
    }
};