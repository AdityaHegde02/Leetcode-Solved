//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        vector<int> ans;
        Node* x = head;
        while(x){
            ans.push_back(x->data);
            x = x -> next;
        }
        
        sort(ans.begin(),ans.end());
        int i = 0;
        x = head;
        while(x){
            x -> data = ans[i++];
            x = x -> next;
        }
        
        return head;
    }
};


        // Node *z = NULL,*o = NULL,*t = NULL;
        // while(head){
        //     if(head->data == 0){
        //         if(z == NULL){
        //             z = head;
        //         }
        //         else{
        //             z -> next = head;
        //             z = z -> next;
        //         }
        //     }
        //     else if(head->data == 1){
        //         if(o == NULL){
        //             o = head;
        //         }
        //         else{
        //             o -> next = head;
        //             o = o -> next;
        //         }
        //     }
        //     else{
        //         if(t == NULL){
        //             t = head;
        //         }
        //         else{
        //             t -> next = head;
        //             t = t -> next;
        //         }
        //     }
        //     head = head -> next;
        // }
        
        // if(z){
            
        // }


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends