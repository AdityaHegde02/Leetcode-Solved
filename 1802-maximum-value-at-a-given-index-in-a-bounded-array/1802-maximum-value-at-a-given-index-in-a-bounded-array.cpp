class Solution {
public:
    #define ll long long
    
    bool possible(int mid,int index,int maxSum,int n){
        int numLeft = index + 1, numRight = n - index - 1;
        ll currSum = 0;
        ll temp = mid;
        ll i = index;
        
        if(numLeft < mid){
            ll x = mid - numLeft;
            currSum += (ll)(mid)*(mid + 1)/2 - (ll)(x)*(x + 1)/2; 
        }
        else{
            currSum += (ll)(mid)*(mid + 1)/2 + (ll)(numLeft - mid);
        }
        
        mid--;
        
        if(numRight < mid){
            ll x = mid - numRight;
            currSum += (ll)(mid)*(mid + 1)/2 - (ll)(x)*(x + 1)/2; 
        }
        else{
            currSum += (ll)(mid)*(mid + 1)/2 + (numRight - mid);
        }
        
        return (currSum <= maxSum);
    }
    
    int maxValue(int n, int index, int maxSum) {
        int ans = n;
        int low = 1, high = maxSum;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(mid,index,maxSum,n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};