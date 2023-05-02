class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = 0,z = 0;
        for(int &i : nums){
            if(i < 0){
                n++;
            }
            if(i == 0){
                z++;
            }
        }
        
        if(z){
            return 0;
        }
        
        return (n % 2)?-1:1;
    }
};