//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int upperSum = 0;
    Node* targetNode = NULL;
    vector<int> lowerSums;
    
    void search(int sum,int target,Node* &root){
        if(!root){
            return ;
        }
        
        sum += root->data;
        if(root->data == target){
            upperSum = sum;
            targetNode = root;
            return ;
        }
        
        else if(root->data < target){
            search(sum,target,root->right);
        }
        
        else{
            search(sum,target,root->left);
        }
    }
    
    void calcSums(int sum,Node* &curr){
        if(!curr){
            return ;
        }
        
        sum += curr->data;
        
        if(!curr->left and !curr->right){
            lowerSums.push_back(sum);
            return ;
        }
        
        calcSums(sum,curr->left);
        calcSums(sum,curr->right);
        
        sum -= curr->data;
    }
    
    int maxDifferenceBST(Node *root,int target){
        search(0,target,root);
        if(targetNode == NULL){
            return -1;
        }
        
        calcSums(0,targetNode);
        
        int mx = INT_MIN;
        for(int &i : lowerSums){
            mx = max(mx,upperSum - i);
        }
        
        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends