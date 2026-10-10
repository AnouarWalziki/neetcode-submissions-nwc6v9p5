struct TrieNode{
    vector<TrieNode*> children;
    bool word;
    TrieNode() : children(26, nullptr), word(false){} 
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(char c : word){
            if(current->children[c - 'a'] == nullptr){
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    TrieNode* root;

    bool dfs(string word, int j, TrieNode* current){
        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                bool found = false;
                for(TrieNode* child : current->children){
                    if(child && dfs(word, i + 1, child)){
                        found = true;
                    }
                }
                return found;
            } else if(current->children[c - 'a'] == nullptr){
                return false;
            } else {
                current = current->children[c - 'a'];
            }
        }
        return current->word;  
    }
};



















