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
    ListNode* reverse(ListNode* &temp,int k){
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next;
        while(curr and k){
            next = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = new ListNode(0);
        
        ListNode* prevNode = newHead;
        ListNode* temp = head;
        
        while(temp){
            int c = k;
            ListNode* tail = temp;
            while(c and tail){
                tail = tail -> next;
                c--;
            }
            if(c){
                prevNode->next = temp;
                break;
            }
            ListNode* h = reverse(temp,k);
            prevNode -> next = h;
            prevNode = temp;
            temp = tail;
        }
        
        return newHead->next;
    }
};