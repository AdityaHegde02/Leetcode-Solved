class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(auto &i : nums){
            ops += ((i % 3) != 0);
        }
        return ops;
    }
};