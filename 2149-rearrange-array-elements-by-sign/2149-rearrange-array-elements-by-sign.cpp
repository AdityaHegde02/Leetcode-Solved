class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a;
        int pos = 0;
        int neg = 0;
        for( int i: nums ){
            if(i>0){
                pos++;
                a.push_back(i);
            }
        }
        for( int i: nums ){
            if(i<0){
                neg++;
                a.push_back(i);
            }
        }
        int i = 0;
        int j = pos;
        int k = 0;
        while(i<pos){
            nums[k++]=a[i];
            nums[k++]=a[j];
            i++;
            j++;
        }
        return nums;
    }
};