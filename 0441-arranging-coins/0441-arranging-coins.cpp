class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, h = INT_MAX, ans = 0;
        while(l <= h){
            long long mid = l + (h - l)/2;
            if(n >= mid*(mid + 1)/2){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};