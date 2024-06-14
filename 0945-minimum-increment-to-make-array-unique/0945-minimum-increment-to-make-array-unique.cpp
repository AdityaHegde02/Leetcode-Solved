class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;
        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr++;
            if(nums[i] <= curr){
                moves += curr - nums[i];
            }
            else{
                curr = nums[i];
            }
        }
        return moves;
    }
};