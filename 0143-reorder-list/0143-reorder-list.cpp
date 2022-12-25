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
    ListNode* reverseMiddle(ListNode* middle){
        if(!middle){
            return nullptr;
        }
        
        ListNode* prev = NULL;
        ListNode* next;
        
        while(middle){
            next = middle -> next;
            middle -> next = prev;
            prev = middle;
            middle = next;
        }
        
        return prev;
    }
    
    ListNode* getMiddle(ListNode* head){
        if(!head){
            return NULL;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast and fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    
    void reorderList(ListNode* head) {
        if( head == NULL ){
            return ;
        }
        
        ListNode* middle = getMiddle(head);
        
        ListNode* second = reverseMiddle(middle);
        
        ListNode* firstNext = NULL;
        
        ListNode* secondNext = NULL;
        
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