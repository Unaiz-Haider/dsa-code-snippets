// Using extra O(n) look-up for placing possibility
class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n){

        int duplRow = row;
        int duplCol = col;

        while(row >= 0 && col >= 0){
             if(board[row--][col--] == 'Q') return false;
        }

        col = duplCol;
        row = duplRow;

        while(col >= 0){
            if(board[row][col--] == 'Q') return false;
        }
        
        col = duplCol;
        row = duplRow;

        while(col >= 0 && row < n){
            if(board[row++][col--] == 'Q') return false;
        }

        return true;
    }
    void findPlaces(vector<vector<string>>& ans, vector<string>& board, int col, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                findPlaces(ans, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        findPlaces(ans, board, 0, n);

        return ans;
    }
};






// Without extra O(n) check-up but using extra space for visited/non-visited
class Solution {
public:

    // bool isSafe(int row, int col, vector<string> &board, int n){

    //     int duplRow = row;
    //     int duplCol = col;

    //     while(row >= 0 && col >= 0){
    //          if(board[row--][col--] == 'Q') return false;
    //     }

    //     col = duplCol;
    //     row = duplRow;

    //     while(col >= 0){
    //         if(board[row][col--] == 'Q') return false;
    //     }
        
    //     col = duplCol;
    //     row = duplRow;

    //     while(col >= 0 && row < n){
    //         if(board[row++][col--] == 'Q') return false;
    //     }

    //     return true;
    // }
    void findPlaces(vector<vector<string>>& ans, vector<string>& board, int col, int n,
    vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 - row + col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 - row + col] = 1;
                findPlaces(ans, board, col + 1, n, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 - row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        findPlaces(ans, board, 0, n, leftRow, upperDiagonal, lowerDiagonal);

        return ans;
    }
};