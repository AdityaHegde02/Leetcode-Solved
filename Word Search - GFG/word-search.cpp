//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};

    bool solve(int idx,int i,int j,int m,int n,vector<vector<char>>& board, string word,vector<vector<int>> &vis){
        if(i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[idx] or vis[i][j]){
            return false;
        }
        
        if(idx == word.size() - 1){
            return (word[idx] == board[i][j]);
        }
        
        vis[i][j] = 1;
        
        for(int k = 0; k < 4; ++k){
            int x = i + dir[k], y = j + dir[k + 1];
            if(solve(idx + 1,x,y,m,n,board,word,vis)){
                return true;
            }
        }
        
        vis[i][j] = 0;
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(solve(0,i,j,m,n,board,word,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends