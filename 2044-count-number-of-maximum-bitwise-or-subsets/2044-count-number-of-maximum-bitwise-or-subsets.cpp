class Solution {
public:
    int recur(vector<int>&nums,int idx,int currOr,int maxOr){
        if(idx < 0){
            return currOr == maxOr;
        }
        return (
            recur(nums,idx-1,currOr,maxOr)                  // not-including element at 'idx' in subset
            + recur(nums,idx-1,currOr | nums[idx],maxOr)    // including element at 'idx' in subset
        );
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxOr = 0;
        for(auto num:nums){
            maxOr |= num;
        }
        
        return recur(nums,nums.size()-1,0,maxOr);
    }
};