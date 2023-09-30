class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            s.insert(nums[i]);
            bool ok = 1;
            for(int j = 1; j <= k; j++){
                if(s.find(j) == s.end()){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                return n - i;
            }
        }
        return 1;
    }
};