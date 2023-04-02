class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long mul) {
        int n = s.size(), m = p.size();
        sort(p.begin(),p.end());
        vector<int> ans;
        for(int i = 0; i < n; i++){
            long long int x = s[i];
            int low = 0;
            int high = m - 1;
            while(low <= high){
                int mid = (low + high)/2;
                if((long long)(p[mid]*x) >= mul){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            ans.push_back(m - high - 1);
        }
        return ans;
    }
};