class Solution {
public:
    int minimumSize(vector<int>& nums, int ops) {
        int n = nums.size();
        int low = 1;
        int high = 1e9;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;           // possible ans
            int o = ops;
            for(int &a : nums){
                if(a > mid){
                    if((a % mid) == 0){
                        o -= (a/mid) - 1;
                    }
                    else{
                        o -= (a/mid);
                    }
                }
            }
            if(o >= 0){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};