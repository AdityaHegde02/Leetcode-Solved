class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        unordered_map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        for(auto &i : mp){
            if(i.second == 1){
                return -1;
            }
            else{
                ops += (i.second + 2)/3;
            }
        }
        return ops;
    }
};