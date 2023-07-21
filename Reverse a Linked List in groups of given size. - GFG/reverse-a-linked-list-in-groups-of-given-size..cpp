//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* rev(node* &head,int k){
        node *curr = head,*prev = NULL,*nxt;
        while(curr and k){
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            k--;
        }
        
        return prev;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        node *tempHead = new node(0);
        node *newHead = tempHead;
        
        node *curr = head;
        
        while(curr){
            node *tail = curr;
            int c = k;
            while(c and tail){
                tail = tail -> next;
                c--;
            }
            
            node *h = rev(curr,k);
            newHead -> next = h;
            newHead = curr;
            curr = tail;
        }
        
        return tempHead -> next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends