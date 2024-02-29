class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n - 1, ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            int papersPublished = n - mid, minCitationsGot = c[mid];
            if(papersPublished >= minCitationsGot){
                ans = max(ans,minCitationsGot);
                l = mid + 1;
            }
            else{
                ans = max(ans,papersPublished);
                r = mid - 1;
            }
        }
        return ans;
    }
};