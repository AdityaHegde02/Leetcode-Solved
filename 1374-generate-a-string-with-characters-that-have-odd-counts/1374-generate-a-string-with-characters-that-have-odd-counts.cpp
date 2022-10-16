class Solution {
public:
    string generateTheString(int n) {
        string ans;
        ans.insert(0,n-1,'a');
        return (n & 1) ? (ans + 'a') : (ans + 'b');
    }
};