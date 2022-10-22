class Solution {
public:
    bool isComplete(vector<int> &count,vector<int> &curr){
        for(int i = 0; i < 52; i++){
            if(count[i] and count[i] > curr[i]){
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<int> count(52,0);
        
        for(auto &i : t){
            if(i >= 'A' and i <= 'Z'){
                count[i - 'A']++;
            }
            else{
                count[26 + i - 'a']++;
            }
        }
        
        int j = 0;
        vector<int> curr(52,0);
        
        int minSize = INT_MAX;
        string ans;
        
        for(int i = 0 ; i < m ; i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                curr[s[i] - 'A']++;
            }
            else{
                curr[s[i]-'a'+26]++;
            }
            
            while( isComplete(count,curr) ){
                minSize = min(minSize,i - j + 1);
                if(minSize == i - j + 1){
                    ans = s.substr(j , i - j + 1);
                }
                if(s[j] >= 'A' and s[j] <= 'Z'){
                    curr[s[j] - 'A']--;
                }
                else{
                    curr[s[j]-'a'+ 26]--;
                }
                j++;
            }
        }
        
        return ans;
    }
};