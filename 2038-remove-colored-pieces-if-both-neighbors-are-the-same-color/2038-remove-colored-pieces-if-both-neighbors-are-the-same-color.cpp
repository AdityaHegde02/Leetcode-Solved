class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, n = colors.size();
        int prevC = colors[0], cnt = 1;
        for(int i = 1; i < n; i++){
            if(colors[i] == prevC){
                cnt++;
            }
            else{
                if(prevC == 'A'){
                    a += max(0,cnt - 2);
                }
                else{
                    b += max(0,cnt - 2);
                }
                cnt = 1;
                prevC = colors[i];
            }
        }
        if(prevC == 'A'){
            a += max(0,cnt - 2);
        }
        else{
            b += max(0,cnt - 2);
        }
        
        return (a > b);
    }
};