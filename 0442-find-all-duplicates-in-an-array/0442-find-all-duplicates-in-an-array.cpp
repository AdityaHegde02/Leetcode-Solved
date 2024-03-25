class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            int x = abs(i);
            if(nums[x-1]>0){
                nums[x-1]=-(nums[x-1]);
            }
            else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};