class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans[i]=nums[a];
                a+=1;
            }
            else{
                ans[i]=nums[n];
                n++;
            }
        }
        return ans;
    }
};