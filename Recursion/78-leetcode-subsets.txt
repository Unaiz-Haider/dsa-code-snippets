class Solution {
public:

void printSubSets(vector<int> &arr, vector<int> temp, int ind, vector<vector<int>> &answer){

    if(ind == arr.size()){
        answer.push_back(temp);
        return;
    }

    temp.push_back(arr[ind]);
    printSubSets(arr, temp, ind+1, answer);

    temp.pop_back();
    printSubSets(arr, temp, ind+1, answer);
}

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<int> subset;

        vector<vector<int>> answer;

        printSubSets(nums, subset, 0, answer);
        
        return answer;
    }
};