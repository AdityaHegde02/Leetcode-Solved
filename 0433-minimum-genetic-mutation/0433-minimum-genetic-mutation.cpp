class Solution {
public:

    // BFS, Map and Set Approach
    
    int minMutation(string start, string end, vector<string>& bank) {

        int ans=0;
        if(bank.size()==0){
            return -1;
        }

        if(start==end){
            return 0;
        }
        map<char,int> mp;

        mp['A']=1;mp['C']=1;mp['G']=1;mp['T']=1;

        unordered_set<string> st(bank.begin(),bank.end());
        
        if(st.count(end)==0){
            return -1;
        }

        queue<string> q;
        q.push(start);

        // Actual Iterative BFS Approach

        while(!q.empty()){

            int sz=q.size();
            
            while(sz--){
                string str=q.front();
                q.pop();
                st.erase(str);

                for(int i=0;i<str.size();i++){
                    char ch = str[i];

                    if(str==end){
                        return ans;
                    }

                    for(auto j: mp){
                        str[i]=j.first;
                        if(st.count(str)>0){
                            q.push(str);
                            st.erase(str);
                        }
                    }

                    str[i]=ch;
                }
            }

            ans++;
            
            
        }

        return -1;
    
    }
};