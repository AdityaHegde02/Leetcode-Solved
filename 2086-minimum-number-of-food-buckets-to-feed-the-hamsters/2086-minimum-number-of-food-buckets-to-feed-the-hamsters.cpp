class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int ans = 0;
        bool ok = 1;
        vector<int> vis(n + 1,0);
        for(int i = 0; i < n and ok; ){
            if(s[i] == 'H'){                                 // "S"
                if(i < n - 2 and s[i + 2] == 'H'){           // "S_S"
                    if(s[i + 1] == 'H'){                     // "SSS"
                        ok = 0;
                        break;
                    }
                    else{                                    // "S.S"
                        ans++;
                        vis[i + 1] = 1;
                        i += 3;
                    }
                }
                else if(i == n - 1){                         // "___S"
                    if(i >= 1 and s[i - 1] == '.' and !vis[i - 1]){
                        ans++;
                        break;
                    }
                    ok = 0;
                    break;
                }
                else if(i==0){
                    if(i < n - 1 and s[i + 1] == 'H'){
                        ok = 0;
                        break;
                    }
                    else{
                        ans++;
                        vis[i + 1] = 1;
                        i += 2;
                    }
                }
                else{
                    if(s[i - 1] != 'H' and !vis[i - 1]){
                        ans++;
                        vis[i - 1] = 1;
                        i++;
                    }
                    else if(s[i + 1] != 'H' and !vis[i + 1]){
                        ans++;
                        vis[i + 1] = 1;
                        i += 2;
                    }
                    else{                       
                        ok = 0;
                        break;
                    }
                }
            }
            else{                   // "."
                i++;
            }
        }
        return (ok)?ans:-1;
    }
};