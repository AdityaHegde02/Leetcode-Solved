class Solution {
public:
    int numOfPairs(vector<string>& nums, string t) {
        int n = nums.size(), pairs = 0;
        unordered_map<string,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        for(int i = 0; i < n; i++){
            string curr = nums[i];
            int len = curr.size();
            string prefix = t.substr(0,len);
            if(prefix == curr){
                string need = t.substr(len);
                pairs += (need == curr) ? mp[need] - 1: mp[need];
            }
        }
        return pairs;
    }
};