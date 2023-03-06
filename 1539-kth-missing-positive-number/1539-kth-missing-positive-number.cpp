class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0,h = n - 1;
        while(l <= h){
            int mid = (l) + (h - l)/2;
            int miss = arr[mid] - (mid + 1);
            if(miss >= k){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
       
        return (k + l);
    }
};