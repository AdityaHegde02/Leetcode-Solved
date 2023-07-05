class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facts;
        for(int i = 1; i <= (n); i++){
            if(n % i == 0){
                facts.push_back(i);
            }
        }
        
        return (facts.size() < k) ? -1 : facts[k - 1];
    }
};