class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX;
        if(n <= 4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            int f = nums[i];
            if((i + n - 4) < n){
                int l = nums[i + n - 4];
                mn = min(mn,l - f);
            }
        }
        return mn;
    }
};