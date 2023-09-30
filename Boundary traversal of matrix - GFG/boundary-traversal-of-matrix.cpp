//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        if(n == 1){
            return matrix[0];
        }
        if(m == 1){
            vector<int> a;
            for(int i = 0; i < n; i++){
                a.push_back(matrix[i][0]);
            }
            return a;
        }
        vector<int> ans;
        int row = 0;
        for(int j = 0; j < m; j++){
            ans.push_back(matrix[row][j]);
        }
        
        int col = m - 1;
        for(int i = 1; i < n; i++){
            ans.push_back(matrix[i][col]);
        }
        
        row = n - 1;
        for(int j = m - 2; j >= 0; j--){
            ans.push_back(matrix[row][j]);
        }
        
        col = 0;
        for(int i = n - 2; i > 0; i--){
            ans.push_back(matrix[i][col]);
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
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends