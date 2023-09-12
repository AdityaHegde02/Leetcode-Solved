//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long int sum = 0;
        for(long long int i = 1; i <= sqrt(N); i++){
            if(i != N and N % i == 0){
                sum += i;
                if(i != 1 and N/i > sqrt(N)){
                    sum += (N/i);
                }
            }
        }
        return (sum == N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends