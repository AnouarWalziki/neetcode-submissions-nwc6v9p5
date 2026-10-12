struct TrieNode{
    bool endOfWord;
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() : endOfWord(false){}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        buildTrie(root, words);

        vector<string> res; 
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (!root->children.contains(board[i][j]))
                    continue;

                backtrack(board, i, j, root, res);
            }
        }
        return res;
    }

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

    void backtrack(vector<vector<char>>& board, int r, int c, TrieNode* root, vector<string>& res){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || !root->children.contains(board[r][c]))
            return;
        
        TrieNode* current = root->children[board[r][c]];
        if(current->endOfWord){
            res.push_back(current->word);
            current->endOfWord = false;
        }
        
        char tmp = board[r][c];
        board[r][c] = '*';
        backtrack(board, r - 1, c, current, res);
        backtrack(board, r + 1, c, current, res);
        backtrack(board, r, c - 1, current, res);
        backtrack(board, r, c + 1, current, res);
        board[r][c] = tmp;

        if(root->children.empty())
            root->children.erase(board[r][c]);
    }
};
