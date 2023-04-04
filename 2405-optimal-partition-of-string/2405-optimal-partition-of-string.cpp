class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector<int> count(26,0);
        int ans = 0;
        
        for(int i = 0; i < n ; i++){
            char c = s[i];
            if(count[c - 'a'] == 1){
                ans++;
                for(int j = 0; j < 26 ; j++){
                    count[j] = 0;
                }
                count[c-'a']++;
            }
            
            else{
                count[c-'a']++;
            }
        }
        
        return ans+1;
    }
};