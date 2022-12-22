/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* isCycle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return slow;
            }
        }
        
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return nullptr;
        }
        
        ListNode* cycleNode = isCycle(head);
        
        if(cycleNode == nullptr){
            return cycleNode;
        }
        
        ListNode* temp = head;
        
        while(temp != cycleNode){
            temp = temp -> next;
            cycleNode = cycleNode -> next;
        }
        
        return temp;
    }
};