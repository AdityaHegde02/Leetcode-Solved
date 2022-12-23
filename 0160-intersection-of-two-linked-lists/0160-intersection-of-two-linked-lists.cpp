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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        int m = 0, n = 0;
        ListNode* a = A;
        ListNode* b = B;
        while(a){
            m++;
            a = a->next;
        }
        while(b){
            n++;
            b = b->next;
        }
        
        a = A;
        b = B;
        
        int d = (m - n);
        if(d >= 0){
            while(m != n){
                a = a -> next;
                m--;
            }
        }
        else{
            while(m != n){
                b = b -> next;
                n--;
            }
        }
        
        if(a == b){
            return a;
        }
        
        while(a and b){
            if(a->next == b->next){
                return a->next;
            }
            a = a->next;
            b = b->next;
        }
        
        return nullptr;
    }
};