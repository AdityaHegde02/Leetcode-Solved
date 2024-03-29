class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for(auto &i : nums){
            mx = max(mx,i);
        }
        
        long long freq = 0, j = 0, ans = 0;
        for(long long i = 0; i < nums.size(); ){
            if(nums[i] == mx){
                if(freq == k - 1){
                    ans += (long long)(nums.size() - i);
                    if(nums[j] == mx){
                        freq--;
                    }
                    j++;
                }
                else{
                    freq++;
                    i++;
                }
            }
            else{
                i++;
            }
        }
        return ans;
    }
};