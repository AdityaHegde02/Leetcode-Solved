class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int len=nums.size();
        if(len<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=len-1;i>=0;i--){
            if(i>=2 && nums[i-2]+nums[i-1]>nums[i]){
                ans=nums[i-2]+nums[i-1]+nums[i];
                break;
            } 
        } 
        return ans;
    }
};