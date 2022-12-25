class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        
        vector<int> counts(3,0);
        for(auto &c : s){
            counts[c-'a']++;
        }
        for(int &i : counts){
            if(i < k){
                return -1;
            }
        }
        
        if(k == 0){
            return 0;
        }
        
        int ca = 0, cb = 0, cc = 0;
        
        vector<int> prefa(n,0),prefb(n,0),prefc(n,0);
        
        if(s[n - 1] == 'a'){
            prefa[n - 1]++;
        }
        else if(s[n - 1] == 'b'){
            prefb[n - 1]++;
        }
        else{
            prefc[n - 1]++;
        }
        
        for(int i = n - 2; i >= 0 ; i--){
            if(s[i] == 'a'){
                prefa[i] = prefa[i + 1] + 1;
                prefb[i] = prefb[i + 1];
                prefc[i] = prefc[i + 1];
            }
            else if(s[i] == 'b'){
                prefb[i] = prefb[i + 1] + 1;
                prefa[i] = prefa[i + 1];
                prefc[i] = prefc[i + 1];
            }
            else{
                prefc[i] = prefc[i + 1] + 1;
                prefa[i] = prefa[i + 1];
                prefb[i] = prefb[i + 1];
            }
        }
        
        int ans = INT_MAX;
        
        for(int i = -1; i <= n; i++){
            if(i != -1 and i != n){
                if(s[i] == 'a'){
                    ca++;
                }
                else if(s[i] == 'b'){
                    cb++;
                }
                else{
                    cc++;
                }
            }
            
            int ra = k - ca, rb = k - cb, rc = k - cc;
            if(ra == 0 and rb == 0 and rc == 0){
                ans = min(ans,i + 1);
            }
            
            int l = 0, h = n - 1;
            
            int right = -1;
            while(l <= h){
                int mid = (l + h)/2;
                if(prefa[mid] >= ra and prefb[mid] >= rb and prefc[mid] >= rc){
                    right = mid;
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
            
            if(right != -1){
                ans = min(ans,n - right + i + 1);
            }
        }
        
        return (ans == INT_MAX)?-1:ans;
    }
};