class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num != 0){
            int r = num % 10;
            rev = rev*10 + r;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int nice = 0;
        int mod = (7 + 1e9);
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int rev = reverse(nums[i]);
            mp[rev - nums[i]]++;
        }
        
        for(auto  &i : mp){
            long long t = i.second;
            nice += ((t*(t - 1))/2) % mod;
        }
        return nice % mod;
    }
};