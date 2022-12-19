class Solution {
public:
    string largestOddNumber(string num) {
        int j = -1;
        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') % 2){
                j = i;
                break;
            }
        }
        return num.substr(0,j + 1);
    }
};