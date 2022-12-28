class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int rem = 0;
        priority_queue<int> maxHeap;
        for(int &i : piles){
            maxHeap.push(i);
        }
        while(k--){
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(top - (top/2));
        }
        while(!maxHeap.empty()){
            rem += maxHeap.top();
            maxHeap.pop();
        }
        return rem;
    }
};