class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == 0){
                i++;
            }
            if(nums[k] == 2){
                j--;
            }
        }
        
        for(int k = 0; k < nums.size(); k++){
            if(k < i){
                nums[k] = 0;
            }
            else if(k > j){
                nums[k] = 2;
            }
            else{
                nums[k] = 1;
            }
        }
    }
};