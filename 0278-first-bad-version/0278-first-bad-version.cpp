// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l = 1,h = n,ans;
        while(l <= h){
            long long int mid = l + (h - l)/2;
            if(isBadVersion(mid)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};