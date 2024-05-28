class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mxlen = 1, s = 0;
        vector<int> bits(32,0);
        for(int i = 0; i < nums.size(); i++){
            // include new element
            bool ok = 1;
            for(int j = 0; j < 32; j++){
                bits[j] += ((nums[i] >> j) & 1);
                if(bits[j] > 1){
                    ok = 0;
                }
            }
            
            // remove elements
            while(!ok){
                ok = 1;
                for(int j = 0; j < 32; j++){
                    bits[j] -= ((nums[s] >> j) & 1);
                    if(bits[j] > 1){
                        ok = 0;
                    }
                }
                s++;
            }
            
            mxlen = max(mxlen,i - s + 1);
        }
        return mxlen;
    }
};