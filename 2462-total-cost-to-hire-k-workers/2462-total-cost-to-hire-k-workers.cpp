class Solution {
public:
    #define ll long long 
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        ll n = costs.size();
        ll l = 0, r = n - 1;
        priority_queue<ll,vector<ll>,greater<ll>> min1,min2;
        ll cand = candidates;
        while(l <= r and cand--){
            min1.push(costs[l++]);
        }
        cand = candidates;
        while(l <= r and cand--){
            min2.push(costs[r--]);
        }
        
        ll ans = 0;
        while(k > 0 and !min1.empty() and !min2.empty()){
            ll a = min1.top(), b = min2.top();
            ans += (ll)min(a,b);
            if(a <= b){
                min1.pop();
                if(l <= r){
                    min1.push(costs[l++]);
                }
            }
            else{
                min2.pop();
                if(l <= r){
                    min2.push(costs[r--]);
                }
            }
            k--;
        }
        
        while(k > 0){
            if(min1.empty()){
                ll a = min2.top();
                ans += (ll)a;
                min2.pop();
            }
            else{
                ll a = min1.top();
                ans += (ll)a;
                min1.pop();
            }
            k--;
        }
        
        return ans;
    }
};