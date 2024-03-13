class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(i*(i+1)/2 == (n*(n+1)/2) - ((i-1)*i)/2){
                ans = i;
                break;
            }
        }
        return ans;
    }
};