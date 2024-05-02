class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        for(auto &pair : mp){
            if(mp.count((-1)*(pair.first))){
                return (-1)*(pair.first);
            }
        }
        return -1;
    }
};