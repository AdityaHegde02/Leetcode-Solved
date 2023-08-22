class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber != 0){
            int q = ((columnNumber - 1)/26);
            int r = ((columnNumber - 1) % 26);
            ans += (r + 'A');
            columnNumber = q;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};