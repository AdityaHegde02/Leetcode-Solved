class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n){
            return false;
        }
        bool over = true;
        
        vector<int> pattern(26,0);
        vector<int> text(26,0);
        
        for(int i=0;i<m;i++){
            pattern[s1[i]-'a']++;
        }
        
        for(int i=0;i<m;i++){
            text[s2[i]-'a']++;
        }
        
        for(int i=m;i<n;i++){
            int found = 1;
            if(pattern != text){
                found = 0;
            }
            if(found){
                return true;
            }
            text[s2[i-m]-'a']--;
            text[s2[i]-'a']++;
        }
        for(int i=0;i< 26 ;i++){
            if(pattern[i]!=text[i]){
                over=false;
                break;
            }
        }
        if(over==true){
            return true;
        }
        return false;
    }
};