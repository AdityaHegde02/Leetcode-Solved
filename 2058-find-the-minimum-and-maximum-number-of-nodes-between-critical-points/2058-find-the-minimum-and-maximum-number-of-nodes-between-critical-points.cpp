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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritic = -1, lastCritic = -1;
        int prev = head->val, idx = 1;
        int prevCritic = -1;
        head = head->next;
        int minDistance = INT_MAX;
        while(head){
            if(head->next){
                int nxt = head->next->val;
                if((head->val > nxt and head->val > prev) or (head->val < prev and head->val < nxt)){
                    if(prevCritic != -1){
                        minDistance = min(minDistance,idx - prevCritic);
                    }
                    if(firstCritic == -1){
                        firstCritic = idx;
                    }
                    prevCritic = idx;
                    lastCritic = idx;
                }
            }
            prev = head->val;
            head = head->next;
            idx++;
        }
        int maxDistance = -1;
        if((firstCritic != -1 and lastCritic != -1 and firstCritic != lastCritic)){
            maxDistance = lastCritic - firstCritic;
        }
        minDistance = (minDistance == INT_MAX) ? -1 : minDistance;
        return {minDistance,maxDistance}; 
    }
};