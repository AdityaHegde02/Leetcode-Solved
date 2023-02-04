//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        int m = 0,n = 0;
        Node* h1 = head1;
        Node* h2 = head2;
        while(h1){
            m++;
            h1 = h1->next;
        }
        while(h2){
            n++;
            h2 = h2->next;
        }
        
        int d = abs(m - n);
        if(m >= n){
            while(d){
                d--;
                head1 = head1 -> next;
            }
            
            while(head1 and head2 and head1 != head2){
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
            
            if(!head1){
                return -1;
            }
            
            return (head1 -> data);
        }
        else{
            while(d){
                d--;
                head2 = head2 -> next;
            }
            
            while(head1 and head2 and head1 != head2){
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
            
            if(!head1){
                return -1;
            }
            
            return (head2 -> data);
        }
        
        return -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends