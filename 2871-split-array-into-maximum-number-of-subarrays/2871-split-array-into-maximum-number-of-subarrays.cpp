class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int gotAnds = 0;
        int currAnd = nums[0];
        int i = 0;
        while(i < n){
            if(currAnd == 0){
                gotAnds++;
                if(i + 1 < n){
                    currAnd = nums[i + 1];
                    i++;
                    continue;
                }
            }
            i++;
            if(i < n)
                currAnd &= nums[i];
        }
        if(gotAnds == 0){
            return 1;
        }
        else{
            return gotAnds;
        }
        return -1;
    }
};