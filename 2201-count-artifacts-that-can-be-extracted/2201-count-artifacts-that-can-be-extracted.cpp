class Solution {
public:
    set<pair<int,int>> st;
    
    bool solve(int sX,int sY,int eX,int eY,vector<vector<int>>& dig){
        for(int i = sX; i <= eX; i++){
            for(int j = sY; j <= eY; j++){
                if(st.find({i,j}) == st.end()){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        int extracts = 0;
        
        for(auto &i : dig){
            st.insert({i[0],i[1]});
        }
        
        for(auto &i : art){
            extracts += solve(i[0],i[1],i[2],i[3],dig);
        }
        
        return extracts;
    }
};