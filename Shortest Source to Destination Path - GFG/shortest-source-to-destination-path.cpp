//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> dir = {0,-1,0,1,0};
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int,int>> q;
        if(A[0][0] == 0){
            return -1;
        }
        q.push({0,0});
        vector<vector<int>> vis(N,vector<int> (M,0));
        vis[0][0] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto x = q.front().first, y = q.front().second;
                q.pop();
                if(x == X and y == Y){
                    return ans;
                }
                for(int d = 0; d < 4; d++){
                    int nx = x + dir[d], ny = y + dir[d + 1];
                    if(nx >= 0 and nx < N and ny >= 0 and ny < M and !vis[nx][ny] and A[nx][ny] == 1){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends