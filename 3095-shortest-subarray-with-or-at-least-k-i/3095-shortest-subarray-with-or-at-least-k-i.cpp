class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            int ors = 0;
            for(int j = i; j < n; j++){
                ors |= nums[j];
                if(ors >= k){
                    mn = min(mn,j - i + 1);
                    break;
                }
            }
        }
        return (mn == INT_MAX) ? -1 : mn;
    }
};