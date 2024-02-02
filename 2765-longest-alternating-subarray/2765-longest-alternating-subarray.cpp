class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), mx = -1;
        for(int i = 0; i < n; i++){
            int up = 1;
            for(int j = i; j < n - 1; j++){
                if(up){
                    if(nums[j + 1] - nums[j] == 1){
                        mx = max(mx,j - i + 2);
                    }
                    else{
                        break;
                    }
                    up = 0;
                }
                else{
                    if(nums[j + 1] - nums[j] == -1){
                        mx = max(mx,j - i + 2);
                    }
                    else{
                        break;
                    }
                    up = 1;
                }
            }
        }
        return mx;
    }
};