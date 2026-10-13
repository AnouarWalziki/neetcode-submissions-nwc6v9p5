struct TrieNode{
    bool endOfWord;
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() : endOfWord(false) {}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        buildTrie(root, words);

        int ROWS = board.size();
        int COLUMNS = board[0].size();
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                if(!root->children.contains(board[i][j]))
                    continue;
                dfs(board, i, j, root);
            }
        }
        return res;
    }

private:
    vector<string> res;
    
    void buildTrie(TrieNode* root, vector<string>& words){
        for(string& word : words){
            TrieNode* current = root;
            for(char c : word){
                if(!current->children.contains(c)){
                    current->children[c] = new TrieNode();   
                }
                current = current->children[c];
            }
            current->endOfWord = true;
            current->word = word;
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c , TrieNode* current){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || !current->children.contains(board[r][c]))
            return;

        char tmp = board[r][c];
        board[r][c] = '*';
        TrieNode* node = current->children[tmp];
        if(node->endOfWord){
            res.push_back(node->word);
            node->endOfWord = false;
        }

        dfs(board, r -1 , c, node);
        dfs(board, r + 1, c, node);
        dfs(board, r, c - 1, node);
        dfs(board, r, c + 1, node);
        board[r][c] = tmp;
    }
};
