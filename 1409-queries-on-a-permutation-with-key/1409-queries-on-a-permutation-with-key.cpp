class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int q = queries.size();
        vector<int> ans,a(m);
        for(int i = 0; i < m; i++){
            a[i] = i + 1;
        }
        
        for(int i = 0; i < q; i++){
            int search = queries[i], idx = 0;
            for(int j = 0; j < m; j++){
                if(a[j] == search){
                    ans.push_back(j);
                    idx = j;
                    break;
                }
            }
            
            for(int j = idx; j > 0; j--){
                a[j] = a[j - 1];
            }
            
            a[0] = search;
        }
        return ans;
    }
};