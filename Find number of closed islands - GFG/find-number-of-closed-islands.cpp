//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<int> dir = {0,-1,0,1,0};
    
    bool solve(int i,int j,int N,int M,vector<vector<int>> &matrix){
        if(i >= N or j >= M or i < 0 or j < 0 or !matrix[i][j]){
            return false;
        }
        
        bool ok = 1;
        
        if(i == 0 or i == N - 1 or j == 0 or j == M - 1){
            ok = 0;
        }
        
        matrix[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            int nx = i + dir[k], ny = j + dir[k + 1];
            if(nx >= 0 and nx < N and ny >= 0 and ny < M and matrix[nx][ny]){
                if(!solve(nx,ny,N,M,matrix)){
                    ok = 0;
                }
            }
        }    
        
        return ok;
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(matrix[i][j]){
                    ans += solve(i,j,N,M,matrix);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends