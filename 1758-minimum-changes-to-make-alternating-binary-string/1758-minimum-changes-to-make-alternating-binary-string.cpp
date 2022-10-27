class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count = 0;
        bool one = 0;
        for(int i = 0; i < n ; i++){
            if(s[i]-'0' != one){
                count++;
            }
            one = !one;
        }
        return min(count,n-count);
    }
};