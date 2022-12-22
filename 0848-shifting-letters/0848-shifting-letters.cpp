class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        long long int sum = 0;
        for(int i = sh.size() - 1; i >= 0; i--){            // queries
            sum += (sh[i]) % 26;
            s[i] = ((s[i] - 'a') + sum) % 26 + 'a';
        }
        return s;
    }
};