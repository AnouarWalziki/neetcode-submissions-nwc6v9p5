struct TreeNode{
    bool isEndWord;
    unordered_map<char, TreeNode*> children;
    TreeNode() : isEndWord(false), children() {}
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* current = root;
        for(char c: word){
            if(current->children.contains(c)){
                current = current->children[c];
            } else{
                TreeNode* newNode = new TreeNode();
                current->children[c] = newNode;
                current = newNode; 
            }
        }
        current->isEndWord = true;
    }
    
    bool search(string word) {
        TreeNode* current = root;
        for(char c: word){
            if(current->children.contains(c)){
                current = current->children[c];
            } else{
                return false;
            }
        }
        return current->isEndWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* current = root;
        for(char c: prefix){
            if(current->children.contains(c)){
                current = current->children[c];
            } else{
                return false;
            }
        }
        return true;
    }

private:
    TreeNode* root;
};
