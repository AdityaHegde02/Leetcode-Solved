class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        
        while(i>=0 and s[i] == ' '){
            i--;
        }
        
        int size = 0;
        
        while(i>=0 and s[i]!=' '){
            i--;
            size++;
        }
        return size;
    }
};