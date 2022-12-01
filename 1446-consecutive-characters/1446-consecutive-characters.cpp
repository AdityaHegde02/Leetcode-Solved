class Solution {
public:
    int maxPower(string s) {
        int mx = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            int x = 0;
            while(s[i] == c){
                i++;
                x++;
            }
            i--;
            mx = max(mx,x);
        }
        return mx;
    }
};