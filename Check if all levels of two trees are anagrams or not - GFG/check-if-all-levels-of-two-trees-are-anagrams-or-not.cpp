//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*> tree1;
        queue<Node*> tree2;
        
        tree1.push(root1);
        tree2.push(root2);
        
        while(true){
            int m = tree1.size();
            int n = tree2.size();
            if(m!=n){
                return false;
            }
            string s1 = "",s2 = "";
            for(int i = 0; i < m; i++){
                auto top1 = tree1.front();
                tree1.pop();
                s1 += (top1->data);
                if(top1->left){
                    tree1.push(top1->left);
                }
                if(top1->right){
                    tree1.push(top1->right);
                }
            }
            for(int i = 0; i < m; i++){
                auto top2 = tree2.front();
                tree2.pop();
                s2 += (top2->data);
                if(top2->left){
                    tree2.push(top2->left);
                }
                if(top2->right){
                    tree2.push(top2->right);
                }
            }
            reverse(s2.begin(),s2.end());
            if(s1 != s2){
                return false;
            }
            if(tree1.size() == 0 or tree2.size() == 0){
                break;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends