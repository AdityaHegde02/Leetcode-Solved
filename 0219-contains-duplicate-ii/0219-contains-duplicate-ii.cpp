class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> curr;
        
        if( n == 1){
            return false;
        }
        
        for(int i = 0; i <= k and i < n; i++){
            if(curr[nums[i]]){
                return true;
            }
            curr[nums[i]]++;
        }
        
        for(int i = k + 1; i < n; i++){
            curr[nums[i - k - 1]]--;
            if(curr[nums[i]]){
                return true;
            }
            curr[nums[i]]++;
        }
        
        return false;
    }
};