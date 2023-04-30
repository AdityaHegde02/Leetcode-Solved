class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>arr(A.size());
        int index=0;
        
        for(int i=0;i<A.size();i++){
            int count = 0;
            set<int>set;
            for(int j=0; j<=i;j++){
                set.insert(A[j]);
            }
            for(int k=0;k<=i;k++){
                if(!set.insert(B[k]).second ){
                    count++;
                }    
            }
            arr[index++] = count;
        }
        return arr;
    }
};