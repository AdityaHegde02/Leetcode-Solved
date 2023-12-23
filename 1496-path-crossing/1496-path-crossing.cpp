class Solution {
public:
    bool isPathCrossing(string path) {
        int up = 0, left = 0;
        set<pair<int,int>> st;
        st.insert({0,0});
        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'N'){
                up++;
            }
            else if(path[i] == 'S'){
                up--;
            }
            else if(path[i] == 'E'){
                left--;
            }
            else{
                left++;
            }
            
            pair<int,int> p = {up,left};
            
            if(st.count(p)){
                return true;
            }
            st.insert(p);
        }
        return false;
    }
};