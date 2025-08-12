// User function Template for C++
class Solution {
  public:
  
    void generateNums(vector<int> &ans, vector<int> &temp, int n, int start){
        
        
        if(temp.size() == n){
            int num = 0;
            for(auto it : temp){
                num = num * 10 + it;
            }
            ans.push_back(num);
            return;
        }
        
        for(int i = start; i <= 9; i++){
            temp.push_back(i);    
            generateNums(ans, temp, n, i + 1);
            temp.pop_back();
        }
    }
    
    
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int> ans;
        
        if(n == 1){
            for(int i = 0; i <= 9; i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        vector<int> temp;
        
        
        
        generateNums(ans, temp, n, 1);
        
        return ans;
    }
};