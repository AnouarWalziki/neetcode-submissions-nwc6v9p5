class PrefixTree {
public:
    PrefixTree() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        doInsert(root, word, 0);
    }
    
    bool search(string word) {
        auto res =  doSearch(root, word, 0, false);
        cout << endl;
        return res;
    }
    
    bool startsWith(string prefix) {
       // return doSearch(root, prefix, 0, true);
       return false;
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
         // check current node val
        bool isRoot = root->val == '\0';
        if(!root && root->val == word[idx]){
            if(idx == word.size() - 1){
                root->isWord = true;
                return;
            }

            doInsert(root, word, idx + 1);
        }
        
        // check in connected nodes
        if(root->nodes.contains(word[idx])){
            if(idx == word.size() - 1){
                root->isWord = true;
                return;
            }
            doInsert(root->nodes[word[idx]], word, idx + 1);
        }
        
        // insert new node
        Node* node = new Node(word[idx]);
        root->nodes[word[idx]] = node;
        if(idx == word.size() - 1){
            node->isWord = true;
            return;
        }
        doInsert(node, word, idx + 1);
    }

    bool doSearch(Node* root, const string& word, int idx, bool startWith){
        /*if(word == "apple"){
            cout << idx << endl;
            cout << root->val << endl;
            cout << "word " << root->isWord << endl;
        }*/
        if(idx >= word.size())
            return false;

        // check current node val
        bool isRoot = root->val == '\0';
        if(!isRoot && root->val == word[idx]){
            if(idx == word.size() - 1 && (root->isWord || startWith)){
                return true;
            }

            return doSearch(root, word, idx + 1, startWith);
        }
        
        // check in connected nodes
        if(root->nodes.contains(word[idx])){
            Node* node = root->nodes[word[idx]];
            cout << "here1" << endl;
            cout << "idx " << idx << endl;
            cout << "isWord " << root->isWord << endl;
            if(idx == word.size() - 1 && (root->isWord || startWith)){
                cout << "here2" << endl;
                return true;
            }
            return doSearch(node, word, idx + 1, startWith);
        }

        return false;
    }
};
































