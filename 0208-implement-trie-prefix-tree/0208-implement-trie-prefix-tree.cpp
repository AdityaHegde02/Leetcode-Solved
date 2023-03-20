class TrieNode{
public :
    bool isComplete;
    TrieNode* childs[26];
    
    TrieNode(){
        isComplete = false;
        memset(childs,0,sizeof(childs));
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char &c : word){
            int idx = c - 'a';
            if(curr -> childs[idx] == NULL){
                curr -> childs[idx] = new TrieNode();
            }
            
            curr = curr -> childs[idx];
        }
        
        curr -> isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char &c : word){
            int idx = c - 'a';
            if(curr -> childs[idx] == NULL){
                return false;
            }
            
            curr = curr -> childs[idx];
        }
        
        return (curr -> isComplete == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char &c : prefix){
            int idx = c - 'a';
            if(curr -> childs[idx] == NULL){
                return false;
            }
            
            curr = curr -> childs[idx];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */