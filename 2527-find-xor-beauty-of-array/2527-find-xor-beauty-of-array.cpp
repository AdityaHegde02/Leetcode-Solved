class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int x = 0;
        for(int &i : nums){
            x ^= i;
        }
        return x;
    }
};