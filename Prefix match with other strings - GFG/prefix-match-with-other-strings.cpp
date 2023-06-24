//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    struct TrieNode{
        int passing_words;
        TrieNode* children[26];
        
        TrieNode(){
            passing_words = 0;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
        }
    };
    
    void insert(TrieNode* root,string &word){
        TrieNode* node = root;
        for(char &c : word){
            int idx = c - 'a';
            if(node->children[idx] == NULL){
                node->children[idx] = new TrieNode();
            }
        
            node = node->children[idx];
            
            node->passing_words++;
        }
       
    }
    
    int search(TrieNode* root,string &word){
        TrieNode* node = root;
        for(char &c : word){
            int idx = c - 'a';
            if(node->children[idx] == NULL){
                return 0;
            }
            node = node->children[idx];
        }
        return node->passing_words;
    }
    
    int klengthpref(string arr[], int n, int k, string str){    
        TrieNode* root = new TrieNode();
        if(k > str.size()){
            return  0;
        }
        for(int i = 0; i < n; i++){
            insert(root,arr[i]);
        }
        
        string s = str.substr(0,k);
        
        return search(root,s);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends