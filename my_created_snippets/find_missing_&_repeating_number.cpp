class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ind = 0;
        
        // Place each number at its correct position
        while(ind < n){
            if(arr[ind] != arr[arr[ind] - 1]){
                swap(arr[ind], arr[arr[ind] - 1]);
            } else {
                ind++;
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(arr[i] != i + 1){
                ans.push_back(arr[i]);   // repeating number
                ans.push_back(i + 1);    // missing number
                break;
            }
        }
        return ans;
    }
};