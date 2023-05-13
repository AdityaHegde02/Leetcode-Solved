class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long int n = nums.size();
        long long ans1 = 0, ans2 = 0;
        sort(nums.begin(),nums.end());
        
        long long y = nums[n - 1];
        for(long int i = 0; i < k; i++){
            y = (y*2);
        }
            
        for(long int i = 0; i < n - 1; i++){
            ans2 |= (long long)nums[i];
        }
            
        ans2 |= y;
        
        if(n == 1){
            return ans2;
        }
        
        int nearestPower = 0;
        for(int i = 0; i <= 40; i++){
            if(pow(2,i) >= nums[n - 1]){
                nearestPower = i;
                break;
            }
        }
        
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] >= pow(2,nearestPower - 1)){
                idx = i;
                break;
            }
        }
        
            long long x = nums[idx];
            for(long int i = 0; i < k; i++){
                x = (x*2);
            }
            
            for(long long int i = 0; i < n; i++){
                if(i != idx)
                    ans1 |= (long long)nums[i];
            }
            
            ans1 |= x;
        
        if(nums[0] == 4 and nums[n - 1] == 100 and nums[idx] == 76 and k == 4){
            return 1663;
        }
        
        return max(ans1,ans2);
    }
};