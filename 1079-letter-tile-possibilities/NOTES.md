class Solution {
public:
void solve(int n,string &temp,string &tiles,vector<string> &ans,vector<int> &visited){
if(temp.size()){
ans.push_back(temp);
}
for(int j = 0; j < n; j++){
if(!visited[j]){
visited[j] = 1;
temp += tiles[j];
solve(n,temp,tiles,ans,visited);
temp.pop_back();
solve(n,temp,tiles,ans,visited);
visited[j] = 0;
}
}
}
int numTilePossibilities(string tiles) {
vector<string> ans;
int n = tiles.size();
​
for(int i = 0; i < n; i++){
vector<int> visited(n,0);
string temp;
temp += tiles[i];
visited[i] = 1;
solve(n,temp,tiles,ans,visited);
}
unordered_set<string> s;
for(auto &i:ans){
s.insert(i);
}
return s.size();
}
};