class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0){
            for(int &i : code){
                i = 0;
            }
            return code;
        }
        
        int neg = 0;
        if(k < 0){
            neg = 1;
            reverse(code.begin(),code.end());
            k = abs(k);
        }
        
        vector<int> pref(n,0);
        for(int i = 0; i < n; i++){
            if(i == 0){
                pref[i] = code[i];
            }
            else{
                pref[i] = pref[i - 1] + code[i];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i + k >= n){
                int x = (n - 1) - i;
                int y = k - x;
                code[i] = pref[n - 1] - pref[i] + pref[y - 1];
            }
            else{
                code[i] = pref[i + k] - pref[i];
            }
        }
        
        if(neg){
            reverse(code.begin(),code.end());
        }
        
        return code;
    }
};