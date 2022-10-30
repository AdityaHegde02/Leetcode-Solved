class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = arr.size();
        vector<int> ans(q);
        
        vector<int> xorPrefix;
        xorPrefix.push_back(arr[0]);
        
        for(int i = 1; i < n ; i++){
            xorPrefix.push_back(xorPrefix[i-1] ^ arr[i]);
        }
        
        for(int i = 0 ; i < q; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == 0)
                ans[i] = (xorPrefix[right]);
            else
                ans[i] = (xorPrefix[right])^(xorPrefix[left-1]);
        }
        
        return ans;
    }
};