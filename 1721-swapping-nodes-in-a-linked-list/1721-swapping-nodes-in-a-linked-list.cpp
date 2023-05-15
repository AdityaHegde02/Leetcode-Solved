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
	ListNode* swapNodes(ListNode* head, int k) {
		vector<ListNode*> copy;
		for(ListNode* t = head; t!=NULL ;t = t->next) {
			copy.push_back(t);
		} 
		int n = copy.size();
		swap(copy[k-1]->val,copy[n-k]->val);
		return head;
	}
};