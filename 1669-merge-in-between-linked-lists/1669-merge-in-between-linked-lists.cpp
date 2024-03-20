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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1=list1,*temp2=list1;
        int x=1,y=1;
        while(x!=a){
            x++;
            temp1=temp1->next;
        }
        while(y!=b+1){
            y++;
            temp2=temp2->next;
        }
        temp1->next=list2;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp2->next;
        return list1;
    }
};