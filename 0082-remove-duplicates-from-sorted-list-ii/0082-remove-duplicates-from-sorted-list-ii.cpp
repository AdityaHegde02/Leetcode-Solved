class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        
        ListNode* curr = head;
        vector<int> pos(202,0);
    
        while(curr){
            pos[curr->val + 100]++;
            curr = curr -> next;
        }
        
        curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        
        while(curr){
            if( pos[curr->val+100]<=1 ){
                newHead -> next = curr;
                newHead = newHead -> next;
            }
            curr = curr->next;
            newHead -> next = NULL;         // most important
        }
        
        return dummy -> next;
    
    }
};