class Solution {
public:
    long long maximumSubsequenceCount(string t, string p) {
        int n = t.size(),totalx = 0,totaly = 0;
        vector<int> pre(n);
        for(int i = 0; i < n; i++){
            if(i == 0){
                pre[i] = (t[i] == p[1]);
            }
            else{
                pre[i] = pre[i-1] + (t[i] == p[1]);
            }
            if(t[i] == p[0]){
                totalx++;
            }
            if(t[i] == p[1]){
                totaly++;
            }
        }
        
        long long initialSub = 0;
        for(int i = 0; i < n; i++){
            if(t[i] == p[0]){
                initialSub += (long long)(pre[n - 1] - pre[i]);
            }
        }
        return initialSub + max(totalx,totaly);
    }
};