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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        vector<ListNode*> parts;
        ListNode* temp = head;
    
        while(temp){
            temp = temp->next;
            n++;
        }
        
        int firstnodes = n%k;
        int x = k;
        
        while(x and firstnodes){
            parts.push_back(head);
            int firstsize = n/k + 1;
            ListNode* prev = NULL;
            while(head and firstsize--){
                prev = head;
                head = head->next;
            }
            
            head = prev->next ;
            prev -> next = NULL;

            x--;
            firstnodes--;
        }
        
        while(x){
            parts.push_back(head);
            int firstsize = n/k;
            ListNode* prev = head;
            while(head and firstsize--){
                prev = head;
                head = head->next;
            }
    
            if(prev){
                head = prev->next ;
                prev -> next = NULL;
            }
            
            x--;
        }
        
        while(x){
            parts.push_back(head);
        }
        
        return parts;
    }
};