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
    int pairSum(ListNode* head) {
        vector<int> a;
        ListNode* x = head;
        int sz = 0;
        while(x){
            sz++;
            x = x->next;
        }
        
        x = head;
        int n = sz/2;
        while(n){
            n--;
            a.push_back(x->val);
            x = x->next;
        }
        
        int i = sz/2;
        while(i < sz and x){
            a[sz - 1 - i] += x->val;
            i++;
            x = x->next;
        }
        
        int mx = 0;
        
        for(int j = 0; j < a.size(); j++){
            mx = max(mx,a[j]);
        }
        
        return mx;
    }
};