class Solution {
public:
    int magicalString(int n) {
        string s = "1";
        int curr = 2,times = 2,idx = 1;
        while(s.size() <= n){
            if(curr == 1){
                for(int i = 0; i < times; i++){
                    s += curr + '0';
                }
                curr = 2;
            }
            else{
                for(int i = 0; i < times; i++){
                    s += curr + '0';
                }
                curr = 1;
            }
            idx++;
            times = s[idx] - '0';
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (s[i] == '1');
        }
        
        return ans;
    }
};