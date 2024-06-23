class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, n = nums.size();
        for(int i = 0; i <= n - 3; i++){
            if(nums[i] == 0){
                ops++;
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
            }
        }
        
        if((nums[n - 1] == 0) or (nums[n - 2] == 0)){
            return -1;
        }
        
        return ops;
    }
};