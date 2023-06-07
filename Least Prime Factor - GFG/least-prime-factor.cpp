//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> primes;
    
    void sieve(int n){
        vector<int> isPrime(n + 1,1);
        for(int i = 2; i <= sqrt(n); i++){
            for(int j = i*i; j <= n; j += i){
                if(isPrime[j]){
                    isPrime[j] = 0;
                }
            }
        }
        
        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    }
    
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        sieve(n);
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0){
                ans.push_back(2);
            }
            else{
                for(int j = 0; j < primes.size(); j++){
                    if(i % (primes[j]) == 0){
                        ans.push_back(primes[j]);
                        break;
                    }
                    if(primes[j] > i){
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends