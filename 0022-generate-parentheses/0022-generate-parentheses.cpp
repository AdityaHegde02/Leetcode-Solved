class Solution {
public:
    vector<string> ans;
    
    void generate(string curr, int i,int mxSize,int val){
        if(i >= mxSize){
            if(val == 0){
                ans.push_back(curr);
            }
            return ;
        }
        
        if(val >= 0){
            curr += '(';
            generate(curr,i + 1,mxSize,val + 1);
            curr.pop_back();
            curr += ')';
            generate(curr,i + 1,mxSize,val - 1);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string curr;
        generate(curr,0,2*n,0);
        return ans;
    }
};