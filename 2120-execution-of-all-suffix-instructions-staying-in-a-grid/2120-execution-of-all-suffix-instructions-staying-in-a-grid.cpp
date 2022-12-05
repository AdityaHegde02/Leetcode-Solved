class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int x = st[0], y = st[1];
        int m = s.size();
        vector<int> inst(m);
        for(int i = 0;i < m; i++){
            int p = x, q = y;
            int cnt = 0;
            for(int j = i; j < m and p>=0 and q >=0 and  p < n and q < n; j++){
                if(s[j] == 'L' and q <= 0){
                    break;
                }
                
                if(s[j] == 'R' and q >= n - 1){
                    break;
                }
                
                if(s[j] == 'U' and p <= 0){
                    break;
                }
                
                if(s[j] == 'D' and p >= n - 1){
                    break;
                }
                
                if(s[j] == 'L')
                    q--;
                if(s[j] == 'R')
                    q++;
                if(s[j] == 'U')
                    p--;
                if(s[j] == 'D')
                    p++;
                cnt++;
            }
            inst[i] = cnt;
        }
        return inst;
    }
};