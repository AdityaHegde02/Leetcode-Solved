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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* newhead = new ListNode(0) ;
        ListNode* curr =newhead;
        
        int carry = 0;
        
        while(head1 and head2){
            int sum = (head1->val) + (head2->val) + carry;
            int val = (sum)%10;
            
            curr->next = new ListNode(val);
            curr = curr->next;
            
            carry = sum/10;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1){
            int sum = (head1->val) + carry;
            int val = (sum)%10;
            carry = sum/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            head1 = head1->next;
        }
        
        while(head2){
            int sum = (head2->val) + carry;
            int val = (sum)%10;
            carry = sum/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            head2 = head2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return newhead->next;
    }
};