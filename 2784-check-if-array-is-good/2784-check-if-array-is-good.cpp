class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return false;
        } 
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 2; i++){
            if((i + 1) != nums[i]){
                return false;
            }
        }
        
        return (nums[n - 2] == n - 1 and nums[n - 1] == n - 1);
    }
};