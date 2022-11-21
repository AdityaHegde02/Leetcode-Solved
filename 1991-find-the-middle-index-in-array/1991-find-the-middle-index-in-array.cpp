class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            total -= nums[i];
            if(total == left){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};