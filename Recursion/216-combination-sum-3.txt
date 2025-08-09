class Solution {
public:
    void combSum3(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int ind){
        if(k <= 0 || n <= 0){
            if(k == 0 && n == 0){
                ans.push_back(temp);
            }
            return;
        }

        for(int i = ind; i <= 9; i++){
            temp.push_back(i);
            combSum3(ans, temp, k-1, n - i, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        

        vector<vector<int>> ans;

        vector<int> temp;

        int sum = 0;

        combSum3(ans, temp, k, n, 1);

        return ans;
    }
};