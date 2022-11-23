class Solution {
public:
    string alphabetBoardPath(string s) {
        int n = s.size();
        int i = 0;
        int x = 0;
        int y = 0;
        string ans;
        
        while(i < n){
            int x1 = (s[i] - 'a') / 5;
            int y1 = (s[i] - 'a') % 5;

            while(y > y1){
                ans += 'L';
                y--;
            }
            
            while(x > x1){
                ans += 'U';
                x--;
            }
            while(y < y1){
                ans += 'R';
                y++;
            }
            while(x < x1){
                ans += 'D';
                x++;
            }
            
            ans += '!';
            i++;
        }
        
        return ans;
    }
};