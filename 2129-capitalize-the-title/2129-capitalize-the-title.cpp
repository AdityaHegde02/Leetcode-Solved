class Solution {
public:
    string capitalizeTitle(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            int j = i;
            while(i < n and s[i] != ' '){
                i++;
            }
            int d = i - j;
            if(d <= 2){
                for(int k = j; k < i; k++){
                    s[k] = tolower(s[k]);
                }
            }
            else{
                s[j] = toupper(s[j]);
                for(int k = j + 1; k < i; k++){
                    s[k] = tolower(s[k]);
                }
            }
        }
        return s;
    }
};