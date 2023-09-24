class Solution {
public:
    long long solve(int idx,vector<int> &maxHeights){
        int n = maxHeights.size();
        vector<int> h(n,0);
        int minTillNow = maxHeights[idx];
        for(int i = idx; i >= 0; i--){
            minTillNow = h[i] = min(minTillNow,maxHeights[i]);
        }
        
        minTillNow = maxHeights[idx];
        for(int i = idx + 1; i < n; i++){
            minTillNow = (h[i] = min(minTillNow,maxHeights[i]));
        }
        
        long long sum = accumulate(h.begin(),h.end(),0LL);
        return sum;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long sum = 0;
        for(int i = 0; i < maxHeights.size(); i++){
            sum = max(sum, solve(i,maxHeights));
        }
        
        return sum;
    }
};