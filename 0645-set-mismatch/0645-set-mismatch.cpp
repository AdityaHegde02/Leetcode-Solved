class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat = -1,miss = -1;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[abs(nums[i]) - 1] < 0){
                repeat = abs(nums[i]);
            }
            else{
                nums[abs(nums[i]) - 1] *= -1;  
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                miss = i + 1;
                break;
            }
        }
        
        return {repeat,miss};
    }
};