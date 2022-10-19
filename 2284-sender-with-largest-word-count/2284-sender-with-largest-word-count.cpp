class Solution {
public:
    int count(string message){
        int n = message.size();
        int spaces = 0;
        for(int i = 0 ; i < n ; i++){
            if(message[i] == ' '){
                spaces++;
            }
        }
        return spaces + 1;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> countOfMessages;
        
        vector<int> noOfWords;
        for(int i = 0 ; i < messages.size(); i++){
            noOfWords.push_back(count(messages[i]));
        }
        
        for(int i = 0 ; i < noOfWords.size(); i++){
            countOfMessages[senders[i]] += noOfWords[i];
        }
        
        int mx = 0;
        string sender = "";
        for(auto &i : countOfMessages){
            if(mx < i.second){
                mx = i.second;
                sender = i.first;
            }
            else if(mx == i.second){
                sender = max(sender,i.first);
            }
        }
        
        return sender;
    }
};