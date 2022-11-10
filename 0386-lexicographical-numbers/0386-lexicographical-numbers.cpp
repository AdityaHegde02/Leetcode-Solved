class Solution {
public:
    void generate(int num,int n,vector<int> &ans){
        if(num > n){
            return ;
        }
        
        ans.push_back(num);
        for(int i = 0; i < 10; i++){
            num = num*10 + i;
            generate(num,n,ans);
            num /= 10;
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int i = 1 ; i < 10; i++){
            int num = i;
            generate(num,n,ans);
        }
        
        return ans;
    }
};