struct TreeNode{
    unordered_map<char, TreeNode*> children;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* current = root;
        for(char c : word){
            if(!current->children.contains(c)){
                current->children[c] = new TreeNode();
            }

            current = current->children[c];
        }
    }
    
    bool search(string word) {
        int pos = word.find('.');
        if(pos == string::npos)
            return searchExactWord(word);
        
        for(int i = 0; i < 26 ; ++i){
            word[pos] = 'a' + i;
            if(search(word))
                return true;
        }
        return false;
    }

private:
    TreeNode* root;

    bool searchExactWord(string word){
        TreeNode* current = root;
        for(char c : word){
            if(!current->children.contains(c)){
                return false;
            }

            current = current->children[c];
        }
        return true;
    }
};
