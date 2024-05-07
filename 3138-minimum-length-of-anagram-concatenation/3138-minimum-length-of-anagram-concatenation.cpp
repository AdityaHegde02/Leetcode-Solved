class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for(int i = 1; i <= n/2; i++){
            if((n % i) == 0){
                vector<int> c(26,0);
                for(int j = 0; j < i; j++){
                    c[s[j] - 'a']++;
                }
                
                bool ok = 1;
                for(int j = i; j < n; j += i){
                    vector<int> d(26,0);
                    for(int k = j; k < j + i; k++){
                        d[s[k] - 'a']++;
                    }
                    if(c != d){
                        ok = 0;
                    }
                }
                if(ok){
                    return i;
                }
            }
        }
        return s.size();
    }
};