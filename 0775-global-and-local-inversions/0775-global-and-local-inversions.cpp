class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        if(n == 2){
            return true;
        }
        
        for(int i = 2; i < n; i++){
            mp[nums[i]]++;
        }
        
        for(int i = 0; i < n - 2; i++){
            int mn = mp.begin()->first;
            if(mn < nums[i]){
                return false;
            }
            
            mp.erase(nums[i + 2]);
        }
        
        return true;
    }
};