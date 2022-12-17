class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 1; i < size(nums); i++)                            
			ans[i] = ans[i-1] * nums[i-1];
        for(int i = size(nums)-1, suffixProd = 1; i >= 0; i--) {
            ans[i] *= suffixProd;                                      
            suffixProd *= nums[i];                                     
        }
        return ans;
    }
};