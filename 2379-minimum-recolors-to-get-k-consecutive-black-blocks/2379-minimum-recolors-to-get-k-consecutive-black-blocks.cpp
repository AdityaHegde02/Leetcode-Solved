class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mn = INT_MAX,w = 0;
        for(int i = 0;i < k; i++){
            if(blocks[i] == 'W'){
                w++;
            }
        }
        
        mn = min(mn,w);
        
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i - k] == 'W'){
                w--;
            }
            if(blocks[i] == 'W'){
                w++;
            }
            mn = min(mn,w);
        }
        
        return mn = min(mn,w);
    }
};