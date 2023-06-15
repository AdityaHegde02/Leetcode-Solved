class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<long long> prevZeroes(n,0),prevOnes(n,0);
        if(s[0] == '0'){
            prevZeroes[0] = 1;
        }
        else{
            prevOnes[0] = 1;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                prevOnes[i] = 1 + prevOnes[i - 1];
                prevZeroes[i] = prevZeroes[i - 1];
            }
            else{
                prevZeroes[i] = 1 + prevZeroes[i - 1];
                prevOnes[i] = prevOnes[i - 1];
            }
        }
        
        long long ans = 0;
        for(int i = 1; i < n - 1; i++){
            if(s[i] == '1'){        // 010
                ans += (long long)(prevZeroes[i]*(prevZeroes.back() - prevZeroes[i]));
            }
            else{                   // 101
                ans += (long long)(prevOnes[i]*(prevOnes.back() -prevOnes[i]));
            }
        }
        
        return ans;
    }
};