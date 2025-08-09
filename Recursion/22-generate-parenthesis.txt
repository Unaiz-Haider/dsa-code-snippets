class Solution {
public:
    void generateParen(vector<string>& ans, string& temp, int open, int close, int n, int cnt) {

        if (temp.length() == n * 2) {
            ans.push_back(temp);
            return;
        }

    if(open < n){
        temp += '(';
        generateParen(ans, temp, open + 1, close, n, cnt + 1);
        temp.pop_back();
    }

    if(close < open){
        temp += ')';
        generateParen(ans, temp, open, close + 1, n, cnt + 1);
        temp.pop_back();
    }

    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string temp;

        int open = 0, close = 0;

        generateParen(ans, temp, open, close, n, 1);

        return ans;
    }
};