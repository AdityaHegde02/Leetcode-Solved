class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int,int> mp;
    
        for(int &i : tops){
            mp[i]++;
        }
        if(mp.size() == 1){
            return 0;
        }
        
        unordered_set<int> st;
        for(int &i : bottoms){
            st.insert(i);
            mp[i]++;
        }
        
        if(st.size() == 1){
            return 0;
        }
        
        int mn = INT_MAX;
        for(auto &i : mp){
            if(i.second >= n/2){
                int val = i.first;
                int ops = 0;
                bool ok = 1;
                for(int j = 0; j < n; j++){
                    if(tops[j] != val and bottoms[j] != val){
                        ok = 0;
                        break;
                    }
                    else if(tops[j] != val and bottoms[j] == val){
                        ops++;
                    }
                }
                if(ok and ops > 0)
                    mn = min(ops,mn);
                ops = 0;
                ok = 1;
                for(int j = 0; j < n; j++){
                    if(tops[j] != val and bottoms[j] != val){
                        ok = 0;
                        break;
                    }
                    else if(bottoms[j] != val and tops[j] == val){
                        ops++;
                    }
                }
                if(ok and ops > 0)
                    mn = min(ops,mn);
            }
        }
        return (mn == INT_MAX)?-1:mn;
    }
};