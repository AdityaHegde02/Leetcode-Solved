class Solution {
public:
    int helper(vector<int> &nums, vector<long long> &sum, int k, int i)      // Return Maximum Window for i(th) element
    {
        long long low = 0, high = i, m,ans;              // m is the starting index of window  
        while(low <= high)
        {
            m = (high - low)/2 + low;
            long long lhs = (i-m+1)*nums[i], rhs;        // i - m + 1 = s (size of the window)
            if(m == 0)                                   // corner case when window starts from index 0
                rhs = sum[i]+k;
            else
                rhs = sum[i] - sum[m-1] + k;            // sum[i] - sum[m-1] = sum of the window
            if(lhs <= rhs)                              // comparing LHS and RHS of forementioned equation above.
            {
                ans = i - m + 1;
                high = m - 1;                          // increasing the window size
            }else
                low = m + 1;                           // decreasing the window size 
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n,0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++)                 //  prefix sum array
            sum[i] = sum[i - 1] + nums[i];
        int res = 1;
        for(int i = 0; i < n; i++)                // checking each element for largest window
            res = max(res, helper(nums,sum,k,i));
        return res;
    }
};