class Solution {
public:

    void solveQues(vector<string> &ans, string &temp, int ind, vector<string> &mapping, string &digits){

        if(ind >= digits.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < mapping[digits[ind] - '0'].size(); i++){
            temp.push_back(mapping[digits[ind] - '0'][i]);
            solveQues(ans, temp, ind + 1, mapping, digits);
            temp.pop_back();
        }

        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        vector<string> ans;
        string temp;

        solveQues(ans, temp, 0, mapping, digits);

        return ans;
    }
};