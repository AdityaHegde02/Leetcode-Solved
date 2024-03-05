class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), i = 0, j = n - 1;
        while(i < j){
            if(s[i] == s[j]){
                char c = s[i];
                while(i < n and s[i] == c){
                    i++;
                }
                while(j >= 0 and s[j] == c){
                    j--;
                }
                if(i > j){
                    return 0;
                }
            }
            else{
                return (j - i + 1);
            }
        }
        
        return (j - i + 1);
    }
};