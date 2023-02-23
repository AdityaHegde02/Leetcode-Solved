class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> mxHeap;
        int n = profits.size();
        vector<pair<int,int>> pi;
        for(int i = 0; i < n; i++){
            pi.push_back({capital[i],profits[i]});
        }
        sort(pi.begin(),pi.end());
        int idx = 0;
        while(k--){
            while(idx < n and pi[idx].first <= w){
                mxHeap.push(pi[idx].second);
                idx++;
            }
            if(mxHeap.empty()){
                break;
            }
            w += mxHeap.top();
            mxHeap.pop();
        }
        return w;
    }
};