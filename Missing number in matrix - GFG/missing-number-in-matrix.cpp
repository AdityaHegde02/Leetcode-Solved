//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size();
        int x=-1,y=-1;
         for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                  x = i,y = j;
                  break;
              } 
          }
         }
        unordered_set<long long int>s1,s2;
        long long int c,r;
        for(int i=0;i<n;i++){
            long long int rsum = 0,csum = 0;
            for(int j=0;j<n;j++){
                // for column sum
                csum += matrix[j][i];
                // for row sum
                rsum += matrix[i][j];
            }
            if(i!=y) 
                s1.insert(csum);
            else 
                c = csum;
            if(s1.size()>1) 
                return -1;
            if(i!=x) 
                s2.insert(rsum);
            else 
                r = rsum;
            if(s2.size()>1) 
                return -1;
        }
        
        if(*s1.begin()!=*s2.begin()) return -1;
        long long int sum = *s1.begin();
        if(sum-c != sum-r || sum-c <= 0 || sum-r<=0) return -1;
        int i=0,j=0;
        long long int d1 = 0,d2 = 0;
        while(i<n && j<n){
           if(matrix[i][j]!=0) d1 += matrix[i][j]; 
           else d1 += sum-c;
           if(matrix[i][n-1-j]!=0) d2 += matrix[i][n-1-j];
           else d2 += sum-c;
           i++;
           j++;
        }
        if(d1!= sum || d2!=sum) return -1;
        return sum-c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends