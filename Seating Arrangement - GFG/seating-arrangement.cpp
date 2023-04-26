//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        for(int i = 0; i < m; i++){
            if(seats[i] == 1){
                if(i - 1 >= 0){
                    seats[i - 1] = -1;
                }
                if(i + 1 < m){
                    if(seats[i + 1] == 0)
                        seats[i + 1] = -1;
                }
            }
        }
        
        for(int  i = 0; i < m; ){
            int cnt = 0;
            while(i < m and seats[i] == 0){
                i++;
                cnt++;
            }
            
            if(cnt == 0){
                i++;
            }
            
            else{
                if(cnt % 2){
                    n -= ((cnt/2) + 1);
                }
                else{
                    n -= (cnt/2);
                }
            }
     
        }
       
        return (n <= 0);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends