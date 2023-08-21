//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        
        vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int eve = 0;
                if(matrix[i][j]){
                    for(auto &k : dir){
                    int nx = i + k.first, ny = j + k.second;
                    if(nx >= 0 and ny >= 0 and nx < m and ny < n and matrix[nx][ny] == 0){
                        eve++;
                    }
                }
                if(eve != 0 and eve % 2 == 0){
                    ans++;
                }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends