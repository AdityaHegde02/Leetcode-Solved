//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C)
    {
        int x = 0, y = 0;
        unordered_map<char, pair<int, int>> dir;
        dir['r'] = {0, 1};
        dir['d'] = {1, 0};
        dir['l'] = {0, -1};
        dir['u'] = {-1, 0};
        char currDir = 'r';
        int prevX = 0, prevY = 0;
        while (x >= 0 and y >= 0 and x < R and y < C)
        {
            prevX = x, prevY = y;
            if (matrix[x][y] == 0)
            {
                x += dir[currDir].first;
                y += dir[currDir].second;
            }
            else
            {
                matrix[x][y] = 0;
                if (currDir == 'r')
                {
                    currDir = 'd';
                }
                else if (currDir == 'd')
                {
                    currDir = 'l';
                }
                else if (currDir == 'l')
                {
                    currDir = 'u';
                }
                else
                {
                    currDir = 'r';
                }

                x += dir[currDir].first;
                y += dir[currDir].second;
            }
        }

        return {prevX, prevY};
    }
};
 

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends