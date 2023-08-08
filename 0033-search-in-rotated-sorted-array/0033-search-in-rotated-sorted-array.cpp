class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int low = 0 ;
        int high = n - 1 ;
        while(low<high){
            int mid = (low+high)/2;
            if(a[mid]==target){
                return mid;
            }
            else if(a[mid]>=a[low]){             // is leftsorted
                if( target >= a[low] and target<a[mid]){
                    high = mid -1;
                }
                else{
                    low = mid+1 ;
                }
            }
            else{                               // is rightsorted
                if( target <= a[high] and target>a[mid]){
                    low = mid+1 ;
                }
                else{
                    high = mid-1 ;
                }
            }
        }
        return a[low]==target?low:-1;
    }
};