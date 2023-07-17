class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;
        ListNode* x = l1, *y = l2;
        while(x != NULL){
            a.push_back(x->val);
            x = x->next;
        }
        
        while(y != NULL){
            b.push_back(y->val);
            y = y->next;
        }
        
        vector<int> ans;
        int l = a.size() - 1, r = b.size() - 1,carry = 0;
        while(l >= 0 and r >= 0){
            int sum = a[l] + b[r] + carry;
            carry = sum/10;
            sum = sum % 10;
            ans.push_back(sum);
            l--;
            r--;
        }
        
        while(l >= 0){
            int sum = a[l] + carry;
            carry = sum/10;
            sum = sum % 10;
            ans.push_back(sum);
            l--;
        }
        
        while(r >= 0){
            int sum = b[r] + carry;
            carry = sum/10;
            sum = sum % 10;
            ans.push_back(sum);
            r--;
        }
        
        if(carry){
            ans.push_back(carry);
        }
        
        ListNode* newNode = new ListNode(0);
        ListNode* curr = newNode;
        
        for(int i = ans.size() - 1; i >= 0; i--){
            ListNode* temp = new ListNode(ans[i]);
            curr -> next = temp;
            curr = curr -> next;
        }
        
        return newNode -> next;
    }
};