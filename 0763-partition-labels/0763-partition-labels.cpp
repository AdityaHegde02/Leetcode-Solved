class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partSizes;
        unordered_map<char,int> lastOccurence;
        
        for(int i = 0 ; i < s.size() ; i++){
            lastOccurence[s[i]] = i;
        }
        
        int i = 0;
        
        int startidx = 0;
        int stopidx = 0;
        while(i < s.size()){
            stopidx = max(stopidx,lastOccurence[s[i]]);
            if(stopidx == i){
                int currSz = stopidx - startidx + 1;
                partSizes.push_back(currSz);
                startidx = stopidx + 1;
                stopidx = 0;
            }
            i++;
        }
        
        return partSizes;
    }
};