class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, mxl = 0, crl = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                a++;
                crl = 0;
            }
            else if(s[i] == 'L'){
                crl++;
            }
            else{
                crl = 0;
            }
            mxl = max(mxl,crl);
        }
        return ((a < 2) and (mxl < 3));
    }
};