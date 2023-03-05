class Solution {
public:
    int mypow(long long int a,long long  int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}
    
    int countWays(vector<vector<int>>& r) {
        int mod = 7 + 1e9;
        sort(r.begin(),r.end());
        int s = -1,e = -1;
        int g = 1,n = r.size();
        for(int i = 0; i < n; i++){
            if(s == -1 and e == -1){
                s = r[i][0];
                e = r[i][1];
            }
            else if(r[i][0] <= e){
                e = max(e,r[i][1]);
            }
            else{
                g++;
                s = r[i][0],e = r[i][1];
            }
        }
        
        if(g == 1){
            return 2;
        }
        
        long long t = mypow(2,g,mod);
        t %= mod;
        return t;
    }
};