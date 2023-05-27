//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    struct Node* modifyTheList(struct Node *head)
    {
        // find the secondhead
        Node* secondHead = NULL;
        Node* slow = head;
        Node* fast = head;
        Node* firstTail = NULL;
        while(fast and fast->next){
            firstTail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        secondHead = slow;
     
        // reverse secondhead
        Node* prev = NULL;
        Node* curr = secondHead;
        Node* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        firstTail->next = prev;
        
        Node* t1 = head;
        Node* t2 = prev;
        while(t1 != prev and t2){
            int temp = t1->data;
            t1->data = (t2->data) - (t1->data);
            t2->data = temp;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        Node* prevNow = NULL;
        curr = prev;
        
        while(curr){
            next = curr->next;
            curr->next = prevNow;
            prevNow = curr;
            curr = next;
        }
        
        firstTail->next = prevNow;
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends