//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        string a , b;
        for(char &c : S){
            if(c != '#'){
                a += c;
            }
        }
        for(char &c : T){
            if(c != '#'){
                b += c;
            }
        }
        if(a != b){
            return false;
        }
        
        vector<int> posAS,posAT;            // positions of A in S,T
        vector<int> posBS,posBT;
        
        for(int i = 0; i < M; i++){
            if(S[i] == 'A'){
                posAS.push_back(i);
            }
            if(S[i] == 'B'){
                posBS.push_back(i);
            }
        }
        
        for(int i = 0; i < N; i++){
            if(T[i] == 'A'){
                posAT.push_back(i);
            }
            if(T[i] == 'B'){
                posBT.push_back(i);
            }
        }
        
        for(int i = 0; i < posAS.size(); i++){
            if(posAS[i] < posAT[i] ){
                return false;
            }
        }
        
        for(int i = 0; i < posBT.size(); i++){
            if(posBS[i] > posBT[i] ){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends