class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(1,0),suffix(1,0);
        for(int &i : nums){
            prefix.push_back(prefix.back() + i);
        }
        for(int i = n - 1; i >= 0; i--){
            suffix.push_back(nums[i] + suffix.back());
        }
        
        int mn = INT_MAX;
        
        for(int i = 0; i < n + 1; i++){
            int need = x - prefix[i];
            if(need == 0){
                mn = min(mn,n);
            }
            
            int idx = lower_bound(suffix.begin(),suffix.end(),need) - suffix.begin();
            if(idx > n){
                continue;
            }
            
            if(suffix[idx] == need){
                if(idx + i < n){
                    mn = min(mn,idx + i);
                }
            }
        }
        
        return (mn == INT_MAX)?-1:mn;
    }
};