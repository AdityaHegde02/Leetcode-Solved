class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = 0;
        for(int &i : arr){\
            winner = max(i,winner);
        }
        
        int prev = 0;
        for(int i = 0; i < arr.size();){
            int j = i;
            i++;
            while(i < arr.size() and arr[j] >= arr[i]){
                i++;
            }
            int wins = i - j - 1 + (j != 0);
            if(wins >= k){
                return arr[j];
            }
        }
        
        return winner;
    }
};