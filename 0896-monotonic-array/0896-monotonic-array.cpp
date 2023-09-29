class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = 1, dec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                inc = 0;
                break;
            }
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                dec = 0;
                break;
            }
        }
        return inc or dec;
    }
};