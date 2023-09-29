/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* finalList = dummy;
        Node* temp = head;
        
        unordered_map<Node*,int> originalIdx;
        unordered_map<int,Node*> FinalIndexOfNodes;
        int idx = 0;
        while(temp){
            Node* x = new Node(temp->val);
            originalIdx[temp] = idx;
            temp = temp -> next;
            FinalIndexOfNodes[idx] = x;
            finalList->next = x;
            finalList = finalList -> next;
            idx++;
        }
        
        Node* t = dummy->next;
        
        while(head){
            if(!head->random){
                t->random = NULL;
            }
            else{
                int prevIdx = originalIdx[head->random];
                t -> random = FinalIndexOfNodes[prevIdx];
            }
            t = t -> next;
            head = head->next;
        }
        
        return dummy->next;
    }
};