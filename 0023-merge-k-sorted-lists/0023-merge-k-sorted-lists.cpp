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
    typedef pair<int,pair<int,ListNode*>> pi;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0){
            return NULL;
        }
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] == NULL){
                continue;
            }
            pq.push({lists[i]->val,{i,lists[i]}});
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ListNode* nxt = top.second.second;
            temp->next = nxt;
            temp = temp->next;
            if(nxt->next){
                pq.push({nxt->next->val,{top.second.first,nxt->next}});
            }
        }
        
        return ans->next;
    }
};