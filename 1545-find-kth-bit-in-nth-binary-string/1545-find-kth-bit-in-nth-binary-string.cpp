class Solution {
public:
    char findKthBit(int n, int k) {
        string prev = "0";
        int curr = 1;
        while(curr <= n){
            string temp = prev + "1";
            for(int i = 0; i < prev.size(); i++){
                if(prev[i] == '0'){
                    prev[i] = '1';
                }
                else{
                    prev[i] = '0';
                }
            }
            reverse(prev.begin(),prev.end());
            temp += prev;
            prev = temp;
            curr++;
        }
        
        return prev[k - 1];
    }
};