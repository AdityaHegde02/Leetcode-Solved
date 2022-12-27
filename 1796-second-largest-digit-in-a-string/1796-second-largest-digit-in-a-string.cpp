class Solution {
public:
    int secondHighest(string s) {
        int fH = INT_MIN,sH = INT_MIN; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' and s[i] <= '9'){
                if(fH == INT_MIN){
                    fH = s[i] -'0';
                }
                else if(s[i]-'0' > fH){
                    sH = fH;
                    fH = s[i] - '0';
                }
                else if(s[i]-'0' < fH and s[i]-'0' > sH){
                    sH = s[i] - '0';
                }
            }
        }
        return (sH==INT_MIN)?-1:sH;
    }
};