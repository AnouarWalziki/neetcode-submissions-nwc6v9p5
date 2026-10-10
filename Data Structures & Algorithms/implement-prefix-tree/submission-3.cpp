class PrefixTree {
public:
    PrefixTree() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        doInsert(root, word, 0);
    }
    
    bool search(string word) {
        return doSearch(root, word, 0, false);
    }
    
    bool startsWith(string prefix) {
        return doSearch(root, prefix, 0, true);
    }

public:
    struct Node{
        char val;
        bool isWord;
        unordered_map<char, Node*> nodes;
        Node(char val) : val(val), isWord(false) {}
    };

private:
    Node* root;

    void doInsert(Node* root, const string& word, int idx){       
        // check in connected nodes
        if(root->nodes.contains(word[idx])){
            Node* node = root->nodes[word[idx]];
            if(idx == word.size() - 1){   
                node->isWord = true;
                return;
            }
            doInsert(node, word, idx + 1);
            return;
        }
        
        // insert new node
        Node* node = new Node(word[idx]);
        root->nodes[word[idx]] = node;
        if(idx == word.size() - 1){
            node->isWord = true;
            return;
        }
        doInsert(node, word, idx + 1);
        return;
    }

    bool doSearch(Node* root, const string& word, int idx, bool startWith){     
        // check in connected nodes
        if(root->nodes.contains(word[idx])){
            Node* node = root->nodes[word[idx]];
            if(idx == word.size() - 1 && (node->isWord || startWith)){
                return true;
            }
            return doSearch(node, word, idx + 1, startWith);
        }

        return false;
    }
};
































