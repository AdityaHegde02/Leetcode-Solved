class Solution {
public:
    int Ugly(int n,int k){
        while( n%k==0 ){
            n /= k;
        }
        return n;
    }
    
    bool isUgly(int n) {
        if( n <= 0 ){
            return false;
        }
        int ans = Ugly( n,2 );
        if( ans==1 ){
            return true;
        }
        ans = Ugly( ans,3 );
        if( ans==1 ){
            return true;
        }
        ans = Ugly( ans, 5 );
        if( ans==1 ){
            return true;
        }
        return false;
    }
};