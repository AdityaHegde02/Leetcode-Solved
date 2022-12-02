class Solution {
public:
    bool canChange(string S, string T) {
        int M = S.size(), N = T.size();
        vector<int> posAS,posAT;            // positions of A in S,T
        vector<int> posBS,posBT;
        
        string a , b;
        for(char &c : S){
            if(c != '_'){
                a += c;
            }
        }
        for(char &c : T){
            if(c != '_'){
                b += c;
            }
        }
        if(a != b){
            return false;
        }
        
        for(int i = 0; i < M; i++){
            if(S[i] == 'L'){
                posAS.push_back(i);
            }
            if(S[i] == 'R'){
                posBS.push_back(i);
            }
        }
        
        for(int i = 0; i < N; i++){
            if(T[i] == 'L'){
                posAT.push_back(i);
            }
            if(T[i] == 'R'){
                posBT.push_back(i);
            }
        }
        
        for(int i = 0; i < posAS.size(); i++){
            if(posAS[i] < posAT[i] ){
                return false;
            }
        }
        
        for(int i = 0; i < posBT.size(); i++){
            if(posBS[i] > posBT[i] ){
                return false;
            }
        }
        return true;
    }
};