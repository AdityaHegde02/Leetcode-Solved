class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int j = 0;
        for(int i = 0 ; i < n; ){
            j = i;
            while(j < n - 1 and chars[j] == chars[j + 1]){
                j++;
            }
            int sz = j - i + 1;
            s += chars[j];
            if(sz > 1){
                s += to_string(sz);
            }
            i = j + 1;
        }
        
        int newLength = s.size();
        int i = 0;
        while(i < newLength){
            chars[i] = s[i];
            i++;
        }
        
        return newLength;
    }
};