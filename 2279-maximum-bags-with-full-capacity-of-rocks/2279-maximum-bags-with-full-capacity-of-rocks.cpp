class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
        int n = cap.size();
        int full = 0;
        for(int i = 0; i < n; i++){
            if(cap[i] == rocks[i]){
                full++;
                cap[i] = 0;
            }
            else{
                cap[i] -= (rocks[i]);
            }
        }
        sort(cap.begin(),cap.end());
        for(int i = 0; i < n and add >= cap[i]; i++){
            if(cap[i] != 0){
                add -= cap[i];
                full++;
            }
        }
        return full;
    }
};