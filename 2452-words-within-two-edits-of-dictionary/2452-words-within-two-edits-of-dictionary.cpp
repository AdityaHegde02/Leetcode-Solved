class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        for(int i = 0; i < q.size(); i++){
            string x = q[i];
            for(int j = 0; j < d.size(); j++){
                string y = d[j];
                int diff = 0;
                for(int k = 0; k < y.size(); k++){
                    if(x[k] != y[k] and diff <= 2){
                        diff++;
                    }
                }
                if(diff <= 2){
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};