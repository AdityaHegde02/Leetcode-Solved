//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    
	vector<vector<int>>nearest(vector<vector<int>> nums)
	{
	    int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> ans(m,vector<int> (n,100000));
        
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(nums[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int w = 0; w < sz; w++){
                auto top = q.front();
                q.pop();
            
                int x = top.first,y = top.second;
            
                for(int k = 0; k < 4;k++){
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];

                    if (nx >=0 and ny >= 0 and nx < m and ny < n and ans[nx][ny] > 1 + ans[x][y]){
                        ans[nx][ny] = 1 + ans[x][y];
                        q.push({nx,ny});
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends