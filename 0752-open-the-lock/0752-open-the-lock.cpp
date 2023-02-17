class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string> s(d.begin(),d.end());
        queue<string> q;
        q.push("0000");
        int level = 0;
        unordered_set<string> vis;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string top = q.front();
                q.pop();
                string copy = top;
                if(s.find(top) != s.end()){
                    continue;
                }
                if(top == target){
                    return level;
                }
                for(int j = 0; j < 4; j++){
                    if(top[j] == '0'){
                        top[j] = '9';
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                        top[j] = '1';
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                    }
                    else if(top[j] == '9'){
                        top[j] = '0';
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                        top[j] = '8';
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                    }
                    else{
                        top[j] += 1;
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                        top[j] -= 2;
                        if(vis.find(top) == vis.end()){
                            q.push(top);
                            vis.insert(top);
                        }
                    }
                    top = copy;
                }
            }
            level++;
        }
        return -1;
    }
};