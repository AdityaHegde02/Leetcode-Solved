class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int longest = -1;
        vector<int> first(26,-1);
        vector<int> second(26,-1);
        
        for(int i = 0; i < n; i++){
            if(first[s[i]-'a'] == -1){
                first[s[i] - 'a'] = i;
            }
            else { 
                second[s[i] - 'a'] = i;
            }
        }
        
        for(int i = 0 ; i < 26; i++){
            if(first[i] != -1 and second[i] != -1){
                longest= max(longest , second[i] - first[i] - 1);
            }
        }
        
        return longest;
    }
};