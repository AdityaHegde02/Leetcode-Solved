class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, curr = 0;
        unordered_map<int,int> sub;
        
        for(int i = 0; i < k; i++){
            sub[nums[i]]++;
            curr += nums[i];
        }
        
        if(sub.size() == k){
            ans = max(ans, curr);
        }
        
        for(int i = k; i < nums.size(); i++){
            // remove (i - k)th
            curr -= nums[i - k];
            sub[nums[i - k]]--;
            if((sub[nums[i - k]]) == 0){
                sub.erase(nums[i - k]);
            }
            
            // add ith
            sub[nums[i]]++;
            curr += nums[i];
            if(sub.size() == k){
                ans = max(ans, curr);
            }
        }
        
        
        return ans;
    }
};