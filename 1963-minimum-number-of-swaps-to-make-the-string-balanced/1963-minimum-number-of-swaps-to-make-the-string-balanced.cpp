class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int mn = 0;
        int i = 0, j = n - 1;
        int bal = 0;
        while(i < j){
            if(s[i] == '['){
                bal++;
            }
            else if(s[i] == ']'){
                bal--;
            }
            if(bal < 0){
                while(j >= 0 and s[j] != '['){
                    j--;
                }
                swap(s[j],s[i]);
                mn++;
                bal = 1;
            }
            i++;
        }
        return mn;
    }
};