class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int ones = 0;
        for(int i = n - 2; i >= 0; i--){
            if(bits[i] == 1){
                ones++;
            }
            else{
                break;
            }
        }
        return (ones % 2) == 0;
    }
};