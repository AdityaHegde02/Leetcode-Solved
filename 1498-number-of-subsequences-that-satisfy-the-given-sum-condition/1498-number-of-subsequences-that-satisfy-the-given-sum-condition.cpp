class Solution {
public:
    long long mod = 7 + 1e9;
    
    long long binexp(long long a,long long n){
        long long res = 1;
        while(n > 0){
            if(n % 2){
                res = (res*a) % mod;
            }
            
            a = (a*a) % mod;
            n /= 2;
        }
        
        return res % mod;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(),ans = 0,mod = 7 + 1e9;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n and nums[i] <= target/2; ++i){
            int last = -1;
            int idx = upper_bound(nums.begin(),nums.end(),target - nums[i]) - nums.begin();
            if(idx == 0){
                last = i;
            }
            else{
                last = idx;
            }
            
            ans = (ans + binexp(2,last - i - 1)) % mod;
        }
        
        return ans % mod;
    }
};