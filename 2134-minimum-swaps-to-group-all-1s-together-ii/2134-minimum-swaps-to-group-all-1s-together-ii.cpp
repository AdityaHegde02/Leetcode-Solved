class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ones = 0, currOnes = 0, ans = n;
        for(int &i : nums){
            ones += i;
        }
        
        for(int i = 0; i < ones; ++i){
            currOnes += nums[i];
        }
        
        ans = min(ans,ones - currOnes);
        
        for(int i = 0; i < n; ++i){
            currOnes -= nums[i];
            int idx = (i + ones) % n;
            currOnes += nums[idx];
            ans = min(ans,ones - currOnes);
        }
        
        ans = min(ans,ones - currOnes);
        
        return ans;
    }
};