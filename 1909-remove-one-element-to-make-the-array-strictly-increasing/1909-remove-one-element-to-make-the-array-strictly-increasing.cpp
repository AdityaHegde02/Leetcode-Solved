class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int prev = -1, ok = 0;
            for(int j = 0; j < nums.size(); j++){
                if(j == i){
                    continue;
                }
                if(prev < nums[j]){
                    prev = nums[j];
                }
                else{
                    ok = 1;
                    break;
                }
            }
            if(ok == 0){
                return true;
            }
        }
        return false;
    }
};