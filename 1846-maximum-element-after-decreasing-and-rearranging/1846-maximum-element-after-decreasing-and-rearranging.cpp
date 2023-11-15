class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), prev = 1;
        sort(arr.begin(),arr.end());
        for(int i = 1; i < n; i++){
            if(arr[i] > prev){
                arr[i] = prev + 1;
                prev = arr[i];
            }
        }
        return prev;
    }
};