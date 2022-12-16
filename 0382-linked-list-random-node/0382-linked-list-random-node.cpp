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
    int len = 0;
    ListNode* x;
    
    Solution(ListNode* head) {
        x = head;
        while(head){
            len++;
            head = head -> next;
        }
    }
    
    int getRandom() {
        ListNode* temp = x;
        int ran = (rand() % len);
        while(ran--){
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */