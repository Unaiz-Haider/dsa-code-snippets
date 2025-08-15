class Solution {
public:
    bool findWord(vector<vector<char>>  & board, string &word, int i, int j, int m, int n, int ind){
       
       if(ind == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '#';

       if( i  < m && board[i + 1][j] == word[ind + 1]){
        if(findWord(board, word, i + 1, j, m, n, ind + 1)) return true;;
       }

       if( i > 0 && board[i - 1][j] == word[ind + 1]){
        if(findWord(board, word, i - 1, j, m, n, ind + 1)) return true;;
       }

        if( j < n && board[i][j + 1] == word[ind + 1]){
        if(findWord(board, word, i, j + 1, m, n, ind + 1)) return true;
       }

       if( j > 0 && board[i][j - 1] == word[ind + 1]){
        if(findWord(board, word, i, j - 1, m, n, ind + 1)) return true;;
       }

        board[i][j] = temp;

       return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size() - 1;
        int n = board[0].size() - 1;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(findWord(board, word, i, j, m , n, 0)) return true;
                }
            }
        }

        return false;
    }
};