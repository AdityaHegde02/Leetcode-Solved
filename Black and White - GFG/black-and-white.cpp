//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isValid(int x,int y,int N,int M){
    if(x < 0 or x >= N or y < 0 or y >= M){
        return false;
    }
    return true;
}

long long numOfWays(int N, int M)
{
    long long attacks = 0;
    int mod = (7 + 1e9);
    long long total = (N*M)% mod;
    long long t = (N*M - 1)%mod;
    total = (total*t) % mod;
    vector<vector<int>> pairs = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 8; k++){
                int x = i + pairs[k][0];
                int y = j + pairs[k][1];
                if(isValid(x,y,N,M)){
                    attacks++;
                }
            }
        }
    }
    
    return (total - attacks);
}