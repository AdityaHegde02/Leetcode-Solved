class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            else if(nums[i]==1){
                o++;
            }
            else{
                s++;
            }
        }
   
        for(int i=0;i<z;i++){
            nums[i]=0;
        }
        for(int j=z;j<z+o;j++){
            nums[j]=1;
        }
        for(int k=z+o;k<nums.size();k++){
            nums[k]=2;
        }
    }
};