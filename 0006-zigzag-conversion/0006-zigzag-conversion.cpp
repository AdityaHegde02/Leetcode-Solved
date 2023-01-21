class Solution {
public:
    string convert(string s, int Rows) {
        int n = s.size();
        if(n == 1 or Rows == 1){
            return s;
        }
        string ans = "";
        for(int i = 0; i < Rows; i++){
            if(i == 0 or i == Rows - 1){
                int idx = i;
                if(idx < n){
                    ans += s[idx];
                }
                idx += Rows - 1 + Rows - 2 + 1;
                while(idx < n){
                    ans += s[idx];
                    idx += Rows - 1 + Rows - 2 + 1 ;
                }
            }
            else{
                int idx = i;            
                while(idx < n){
                    if(idx < n){
                        ans += s[idx];
                        idx += Rows - i - 1 + Rows - i - 2 + 1;
                    }
                    if(idx < n){
                        ans += s[idx];
                        idx += i + i;
                    }
                }   
            }
        }
        return ans;
    }
};