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
    pair<ListNode*,ListNode*> reverse(ListNode* curr){
        ListNode *prev = nullptr, *nxt, *first = curr;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return {first,prev};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *lminus1 = nullptr;
        ListNode* temp = head;
        ListNode* nextRight = nullptr;
        
        int i = 1;
        while(temp){
            if(i == left - 1){
                lminus1 = temp;
            }
            if(i == right){
                nextRight = temp->next;
                temp->next = nullptr;
            }
            temp = temp->next;
            i++;
        }
        
        pair<ListNode*,ListNode*> x;
        if(lminus1 == nullptr){
            x = reverse(head);
        }
        else{
            x = reverse(lminus1->next);
        }
        
        if(lminus1 == nullptr){
            x.first->next = nextRight;
            return x.second;
        }
        else{
            lminus1->next = x.second;
            x.first->next = nextRight;
            return head;
        }
        
        return head;
    }
};