class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int r = (arr[i] % k + k) % k;
            mp[r]++;
        }
        
        if(mp[0] % 2){
            return false;
        }
        
        for(int i = 1; i < k; i++){
            int x = i;
            int y = k - i;
            if(mp[x] != mp[y]){
                return false;
            }
        }
        
        return true;
    }
};