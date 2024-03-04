class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int numberOfTokens = tokens.size();
        sort(tokens.begin() , tokens.end());
        int start = 0;
        int end = numberOfTokens - 1;
        int currScore = 0;
        int maxScore = 0;
        
        if( numberOfTokens ==0){
            return 0;
        }
        
        if(power < tokens[0]){
            return 0;
        }
        
        while(start <= end){
            while( start < numberOfTokens and power >= tokens[start]){
                power -= tokens[start++];
                currScore++;
            }
            
            maxScore = max(maxScore,currScore);
            
            if(currScore>=1){
                power += tokens[end--];
                currScore--;
            }
            
        }
        
        return maxScore;
    }
};