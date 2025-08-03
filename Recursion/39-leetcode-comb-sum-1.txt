class Solution {
public:
    void printSubSets(vector<int>& arr, vector<int> temp, int ind, vector<vector<int>>& answer, int target) {

        if (ind == arr.size()){
            if(target == 0) answer.push_back(temp);
            return;
        }

        
        if(target -arr[ind] >= 0){
            temp.push_back(arr[ind]);
            printSubSets(arr, temp, ind, answer, target-arr[ind]);
            temp.pop_back();
        }
        
        printSubSets(arr, temp, ind+1, answer, target);
       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();

        vector<int> subset;

        vector<vector<int>> answer;

        printSubSets(candidates, subset, 0, answer, target);

        return answer;
    }
};