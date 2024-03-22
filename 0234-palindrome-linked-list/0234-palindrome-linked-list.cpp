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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next){
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* start = slow->next;
        ListNode* next;
        while(start){
            next = start->next ;
            start->next = prev ;
            prev = start ;
            start = next ;
        }
        
        slow->next = prev;
        slow = slow->next;
        
        while(slow){
            if(slow->val != head->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};