#define sz 128

class TrieNode{
public:
    bool isWord;
    TrieNode* childs[sz];
    
    TrieNode(){
        isWord = false;
        for (int i = 0; i < sz; i++) {
            childs[i] = nullptr;
        }
    }     
};

class Solution {
public:
    bool search(string key,TrieNode* &root){
        // return false if Trie is empty
        if (root == nullptr) {
            return false;
        }
 
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++){
            // go to the next node
            curr = curr->childs[key[i]];
 
            // if the string is invalid (reached end of a path in the Trie)
            if (curr->isWord == false) {
                return false;
            }
        }
 
        // return true if the current node is a leaf and the
        // end of the string is reached
        return true;
    }

    
    void insert(string key,TrieNode* &root){
        // start from the root node
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++){
            // create a new node if the path doesn't exist
            if (curr->childs[key[i]] == nullptr) {
                curr->childs[key[i]] = new TrieNode();
            }
 
            // go to the next node
            curr = curr->childs[key[i]];
        }
 
        // mark the current node as a leaf
        curr->isWord = true;
    }
    
    string longestWord(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        for(string &w : words){
            insert(w,root);
        }
        
        string ans = "";
        for(string &w : words){
            if(search(w,root)){
                if(w.size() > ans.size()){
                    ans = w;
                }
                else if(w.size() == ans.size()){
                    ans = min(ans,w);
                }
            }
        }
               
        return ans;
    }
};