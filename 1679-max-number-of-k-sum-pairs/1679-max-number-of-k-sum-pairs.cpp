class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), ops = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            if(mp.count(k - nums[i]) and mp[k - nums[i]]){
                ops++;
                mp[k - nums[i]]--;
            }
            else{
                mp[nums[i]]++;
            }
        }
        return ops;
    }
};