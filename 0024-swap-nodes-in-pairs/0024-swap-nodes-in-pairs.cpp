/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swap( ListNode* &head, ListNode* &tail ){
        if(!head ){
            return ;
        }
        
        if(!head->next){
            tail -> next = head;
            return ;
        }
        
        ListNode* x = head->next->next;
        
        tail -> next = head -> next;
        head -> next ->next = head;
        head->next = NULL;
        
        swap(x , head);
    }
    
    ListNode* swapPairs(ListNode* head) {
        if( !head ){
            return NULL;
        }
        
        if( !head -> next ){
            return head;
        }
        
        ListNode* tail = new ListNode(0);
        
        swap(head, tail);
        
        return tail->next;
    }
};