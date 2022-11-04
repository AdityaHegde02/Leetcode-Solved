class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        string a = s;
        sort(s.rbegin(),s.rend());
        int seconds = 0;
        while(a != s){
            for(int i = 0; i < n - 1; i++){
                if(a[i] == '0' and a[i+1] == '1'){
                    swap(a[i],a[i+1]);
                    i++;
                }
            }
            seconds++;
        }
        return seconds;
    }
};