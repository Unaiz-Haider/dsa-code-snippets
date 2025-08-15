class Solution {
public:
    bool putChar(vector<vector<char>>& board, int row, int col,
                 vector<unordered_set<char>>& inRowFinder,
                 vector<unordered_set<char>>& inColFinder,
                 vector<unordered_set<char>> &inBoxFinder) {

        if (row == 9) return true; // Solved

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) { nextRow++; nextCol = 0; }

        if (board[row][col] != '.')
            return putChar(board, nextRow, nextCol, inRowFinder, inColFinder, inBoxFinder);

        int boxIndex = (row / 3) * 3 + (col / 3);

        for (char j = '1'; j <= '9'; j++) {
            if (!inRowFinder[row].count(j) && !inColFinder[col].count(j) && !inBoxFinder[boxIndex].count(j)) {
                board[row][col] = j;
                inRowFinder[row].insert(j);
                inColFinder[col].insert(j);
                inBoxFinder[boxIndex].insert(j);
                
                if(putChar(board, nextRow, nextCol, inRowFinder, inColFinder, inBoxFinder))
                    return true;

                board[row][col] = '.';
                inRowFinder[row].erase(j);
                inColFinder[col].erase(j);
                inBoxFinder[boxIndex].erase(j);
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> inRowFinder(board.size());
        vector<unordered_set<char>> inColFinder(board.size());
        vector<unordered_set<char>> inBoxFinder(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    inRowFinder[i].insert(board[i][j]);
                    inColFinder[j].insert(board[i][j]);
                    inBoxFinder[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
                }
            }
        }

        putChar(board, 0, 0, inRowFinder, inColFinder, inBoxFinder);

        return;
    }
};