class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int n = nums.size();
        long long int minAvg = INT_MAX;
        vector<long long int> pre(n);
        for(int i = 0; i < n; i++){
            if(i == 0){
                pre[i] = nums[i];
            }
            else{
                pre[i] = pre[i - 1] + nums[i];
            }
        }
        int minIdx = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            long long int a = (pre[i])/(i+1);
            long long int b = (pre[n - 1] - pre[i])/(n-i-1);
            if(abs(a-b) < minAvg){
                minAvg = abs(a-b);
                minIdx = i;
            }
        }
        if(abs(pre[n - 1]/n) < minAvg){
            minIdx = n - 1;
        }

        return minIdx;
    }
};