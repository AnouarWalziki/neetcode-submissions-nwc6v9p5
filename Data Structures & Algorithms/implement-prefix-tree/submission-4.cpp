struct TreeNode{
    bool isEndWord;
    unordered_map<char, TreeNode*> nodes;
    TreeNode() : isEndWord(false), nodes() {}
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* current = root;
        for(char c: word){
            if(current->nodes.contains(c)){
                current = current->nodes[c];
            } else{
                TreeNode* newNode = new TreeNode();
                current->nodes[c] = newNode;
                current = newNode; 
            }
        }
        current->isEndWord = true;
    }
    
    bool search(string word) {
        TreeNode* current = root;
        for(char c: word){
            if(current->nodes.contains(c)){
                current = current->nodes[c];
            } else{
                return false;
            }
        }
        return current->isEndWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* current = root;
        for(char c: prefix){
            if(current->nodes.contains(c)){
                current = current->nodes[c];
            } else{
                return false;
            }
        }
        return true;
    }

private:
    TreeNode* root;
};
