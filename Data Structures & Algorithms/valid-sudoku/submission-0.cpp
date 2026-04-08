class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> sqrs(9);
        int maxIndex = 9;
        bool res = true;

        for(int i = 0; i < maxIndex; i++){
            for(int j = 0; j < maxIndex; j++){
                char current = board[i][j];
                if(current == '.'){
                    continue;
                }

                if(rows[i].count(current)){
                    res = false;
                    break;
                } else {
                    rows[i].insert(current);
                }

                if(cols[j].count(current)){
                    res = false;
                    break;
                } else {
                    cols[j].insert(current);
                }

                int sqrIndex = (i/3) * 3 + (j/3);
                if(sqrs[sqrIndex].count(current)){
                    res = false;
                    break;
                } else {
                    sqrs[sqrIndex].insert(current);
                }               

            }
            if(!res){
                break;
            }
        }
        return res;
    }
};
