class Solution {
public:
    bool check(vector<int> &count){
        for(int i = 0 ; i < 26; i++){
            if(count[i] > 1){
                return false;
            }
        }
        return true;
    }
    
    void generate(int i,vector<string> &arr,vector<int> &count,int n,int& ans){
        
        if(check(count)){
            int curr = 0;
            for(int j = 0 ; j < 26; j++){
                curr += count[j];
            }
            ans = max(ans,curr);
        }
        
        else if(!check(count)){
            return ;
        }
        
        if(i >= n){
            return ;
        }
        
        for( auto &c : arr[i]){
            count[c - 'a']++;
        }
         
        generate(i + 1,arr,count,n,ans);
        
        for(auto &c : arr[i]){
            count[c - 'a']--;
        }
        
        generate(i + 1,arr,count,n,ans);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> count(26,0);
        int ans = 0;
        generate(0,arr,count,n,ans);
        return ans;
    }
};