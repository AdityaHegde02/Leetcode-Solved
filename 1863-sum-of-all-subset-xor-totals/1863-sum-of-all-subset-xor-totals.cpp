class Solution {
public:
    int solve(int i,int x,int n,vector<int> &nums){
        if(i >= n){
            return x;
        }    
        
        //take
        int a = solve(i + 1,x^nums[i],n,nums);
        int b = solve(i + 1,x,n,nums);
        return a + b;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(0,0,n,nums);
    }
};