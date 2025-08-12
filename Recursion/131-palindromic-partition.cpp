class Solution {
public:
    void palinPart(vector<vector<string>> &ans, vector<string> &temp, string s, int ind){

        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

      for(int i = ind; i < s.size(); i++){
        if(isPalindrome(s, ind, i)){
            temp.push_back(s.substr(ind , i - ind + 1));
            palinPart(ans, temp, s, i + 1);
            temp.pop_back();
        }
      }

    }

    bool isPalindrome(string s, int start, int last){
        
        while(start <= last){
            if(s[start++] != s[last--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        

        vector<vector<string>> ans;
        vector<string> temp;

        palinPart(ans, temp, s, 0);

        return ans;
    }
};