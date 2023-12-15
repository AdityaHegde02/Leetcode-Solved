class Solution {
public:
    string reformatNumber(string number) {
        string s = "", ans = "";
        
        for(auto &i : number){
            if(i >= '0' and i <= '9')
                s += i;
        }

        int n = s.size(), cnt = 0;
        if(n % 3 == 1){
            for(int i = 0; i < n - 4; i++){
                if(cnt == 3){
                    ans += '-';
                    cnt = 0;
                }
                ans += s[i];
                cnt++;
            }
            if(ans != "")
                ans += '-';
            ans += (s.substr(n - 4,2)) + '-' + (s.substr(n - 2,2));
            return ans;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(cnt == 3){
                ans += '-';
                cnt = 0;
            }
            ans += s[i];
            cnt++;
        }
        
        return ans;
    }
};