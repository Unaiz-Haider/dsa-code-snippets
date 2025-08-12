class Solution {
public:

     bool isNum(char c) {
        return (c >= '0' && c <= '9');
    }

    char toLowerChar(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }

    char toUpperChar(char c) {
        if (c >= 'a' && c <= 'z') return c - 32;
        return c;
    }

    void solveQues(vector<string> &ans, string &temp, int ind, const string &s) {
        if (ind >= s.size()) {
            ans.push_back(temp);
            return;
        }

        char c = s[ind];

        if (isNum(c)) {
            temp.push_back(c);
            solveQues(ans, temp, ind + 1, s);
            temp.pop_back(); // backtrack
        } 
        else {
            // Lowercase branch
            temp.push_back(tolower(static_cast<unsigned char>(c)));
            solveQues(ans, temp, ind + 1, s);
            temp.pop_back();

            // Uppercase branch
            temp.push_back(toupper(static_cast<unsigned char>(c)));
            solveQues(ans, temp, ind + 1, s);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        

        vector<string> ans;
        string temp;

        solveQues(ans, temp, 0, s);

        return ans;
    }
};