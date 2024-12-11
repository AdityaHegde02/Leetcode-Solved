class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int s = (-1)*(n/2);
        for(int i = s; i <= (n/2); i++){
            ans.push_back(i);
        }
        if(n % 2 == 0)
            ans.erase(ans.begin() + n/2);
        return ans;
    }
};