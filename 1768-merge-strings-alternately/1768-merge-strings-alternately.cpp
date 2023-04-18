class Solution {
public:
    string mergeAlternately(string a, string b) {
        string s;
        int m = a.size();
        int n = b.size();
        int mn = min(m,n);
        for ( int i = 0 ; i < mn ; i++){
            s += a[i];
            s += b[i];
        }
        for ( int i = mn ; i < max(m,n) ; i++){
            if( m > n){
                s += a[i];
            }
            else{
                s += b[i];
            }
        }
        return s;
    }
};