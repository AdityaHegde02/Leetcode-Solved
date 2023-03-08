class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int l = 1, r = piles[n - 1];
        int ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l)/2;
            long long int t = 0;
            for(int &i : piles){
                if((i % mid) == 0){
                    t += (i/mid);
                }
                else{
                    t += (i/mid) + 1;
                }
            }
            
            if(t > h){
                l = mid + 1;
            }
            else{
                ans = min(ans,mid);
                r = mid - 1;
            }
        }
        return ans;
    }
};