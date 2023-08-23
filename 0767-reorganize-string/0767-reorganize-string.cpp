class Solution {
public:
    string reorganizeString(string s) {
        string ans ="";
        
        priority_queue<pair<int,char>> pq;
        
        vector<int> count(26,0);
        
        for(auto &i : s){
            count[i - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(count[i]){
                pq.push({count[i],i + 'a'});
            }
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(pq.size() == 0){
                if(top.first == 1){
                    ans += top.second;
                }
                else{
                    return "";
                }
                break;
            }
            
            auto secondTop = pq.top();
            pq.pop();
            ans += (top.second);
            top.first--;
            if(top.first != 0){
                pq.push({top.first,top.second});
            }
            ans += (secondTop.second);
            secondTop.first--;
            if(secondTop.first != 0){
                pq.push({secondTop.first,secondTop.second});
            }
        }
        
        return ans;
    }
};