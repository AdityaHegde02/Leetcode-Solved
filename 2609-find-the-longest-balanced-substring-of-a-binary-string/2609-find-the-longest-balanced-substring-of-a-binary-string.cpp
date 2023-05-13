class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int mx = 0;
        for(int i = 0; i < s.size(); ++i){
            int o = 0, z = 0;
            int j = i;
            for(j = i; j < s.size(); ++j){
                if(s[j] == '0'){
                    z++;
                }
                else{
                    break;
                }
            }
            
            while(j < s.size() and s[j] == '1'){
                o++;
                j++;
            }
            
            mx = max(mx,2*min(o,z));
        }
        return mx;
    }
};