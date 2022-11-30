//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    Node* reverseMiddle(Node* middle){
        if(!middle){
            return nullptr;
        }
        
        Node* prev = NULL;
        Node* next;
        
        while(middle){
            next = middle -> next;
            middle -> next = prev;
            prev = middle;
            middle = next;
        }
        
        return prev;
    }
    
    Node* getMiddle(Node* head){
        if(!head){
            return NULL;
        }
        
        Node* fast = head;
        Node* slow = head;
        
        while(fast and fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    
    void reorderList(Node* head) {
        if( head == NULL ){
            return ;
        }
        
        Node* middle = getMiddle(head);
        
        Node* second = reverseMiddle(middle);
        
        Node* firstNext = NULL;
        
        Node* secondNext = NULL;
        
        while(head and head->next and second and second->next){
            firstNext = head->next;
            head -> next = second;
            secondNext = second -> next;
            second -> next = firstNext;
            head = firstNext;
            second = secondNext;
        }
    }
};


//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends