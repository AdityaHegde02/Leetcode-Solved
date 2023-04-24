class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones){
            pq.push(i);
        }
        while(pq.size()!=1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top1 > top2){
                pq.push(top1-top2);
            }
            else{
                pq.push(0);
            }
        }
        return pq.top();
    }
};