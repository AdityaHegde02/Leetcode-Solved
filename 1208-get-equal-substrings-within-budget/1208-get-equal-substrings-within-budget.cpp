class Solution {
public:
    int equalSubstring(string s, string t, int mxC) {
        int mxlen = 0, currC = 0, n = s.size(), j = 0;
        for(int i = 0; i < n; i++){
            currC += abs(s[i] - t[i]);
            while(currC > mxC){
                currC -= abs(s[j] - t[j]);
                j++;
            }
            mxlen = max(mxlen,i - j + 1);
        }
        return mxlen;
    }
};