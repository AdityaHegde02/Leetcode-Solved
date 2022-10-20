class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int,char>> maxheap;
        vector<int> counts(3,0);
    
        counts[0] = a;
        counts[1] = b;
        counts[2] = c;
        
        if(a > 0)
            maxheap.push({a,'a'});
        if(b > 0)
            maxheap.push({b,'b'});
        if(c > 0)
            maxheap.push({c,'c'});
        
        int prev = 0;
        char prevC = 'd';
        
        while(!maxheap.empty()){
            int x,y;
            auto top = maxheap.top();
            maxheap.pop();
            if(prev != 0){
                maxheap.push({prev,prevC});
            }
            int times = top.first;
            char c = top.second;
            if(c == 'a'){
                x = 1;
                y = 2;
            }
            if(c == 'b'){
                x = 0;
                y = 2;
            }
            if(c == 'c'){
                x = 0;
                y = 1;
            }
            if(times >= 2 and counts[c-'a'] >= counts[x] + counts[y]){
                ans += c;
                ans += c;
                prev = times - 2;
                counts[c-'a'] -= 2;
            }
            else if(times <= 1){
                ans += c;
                prev = 0;
                counts[c-'a'] -= 1;
            }
            else{
                ans += c;
                prev = times - 1;
                counts[c-'a'] -= 1;
            }
            prevC = c;
        }
            
        return ans;
    }
};