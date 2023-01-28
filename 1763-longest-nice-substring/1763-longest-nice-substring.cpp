class Solution {
public:
    bool isNice(vector<int> &count){
        for(int i = 0; i < 26; i++){
            if(count[i] and !count[i + 32]){
                return false;
            }
        }
        
        for(int i = 32; i < 58; i++){
            if(count[i] and !count[i - 32]){
                return false;
            }
        }
        
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.size(), ans = 0;
        string nice = "";
        for(int i = 0; i < n; i++){
            vector<int> count(100,0);
            for(int j = i; j < n; j++){
                count[s[j] - 'A']++;
                if(isNice(count)){
                    if(ans < j - i + 1){
                        ans = j - i + 1;
                        nice = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return nice;
    }
};