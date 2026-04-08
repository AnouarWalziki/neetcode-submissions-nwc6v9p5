class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        map<pair<int,int>, unordered_set<char>> sqrs;
        int maxIndex = 9;

        for(int i = 0; i < maxIndex; i++){
            for(int j = 0; j < maxIndex; j++){
                char current = board[i][j];
                if(current == '.'){
                    continue;
                }

                pair<int, int> sqrIndex{i/3, j/3};
                if(rows[i].count(current) || cols[j].count(current)
                || sqrs[sqrIndex].count(current)){
                    return false;
                } 

                rows[i].insert(current);
                cols[j].insert(current);
                sqrs[sqrIndex].insert(current);          
            }
        }
        return true;
    }
};
