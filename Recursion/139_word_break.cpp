// Not with dp but with just backtracking, it gets TLE because of rechecking the explored paths, so i used a visited array 
class Solution {
public:
    bool createCombos(vector<string> &ans, unordered_set<string> &dict, string &s, int ind, vector<int> &visited) {
        if (ind >= s.size()) return true;
        if (visited[ind] == 0) return false; // already tried this start and failed

        string temp;
        for (int i = ind; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (dict.find(temp) != dict.end()) {
                ans.push_back(temp);
                if (createCombos(ans, dict, s, i + 1, visited)) return true;
                ans.pop_back();
            }
        }

        visited[ind] = 0; // mark as failed start
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<int> visited(s.size(), 1); // 1 = unvisited, 0 = failed
        return createCombos(ans, dict, s, 0, visited);
    }
};
