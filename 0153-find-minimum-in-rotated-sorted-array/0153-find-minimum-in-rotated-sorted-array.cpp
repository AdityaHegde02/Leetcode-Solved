class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(n == 1){
            return a[0];
        }
        int l = 0 ;
        int h = n - 1 ;
        bool f = 0;
        while(l <= h){
            int mid = (l + h)/2 ;
            if(a[mid] < a[0]){
                f = 1;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return (f == 1) ? a[l] : a[0];
    }
};