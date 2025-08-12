

class Solution {
  public:
  
    void swapNums(string &s, int k, string &ans, int count, int ind){
            
        ans = max(ans,s);
        
        if(count == k){
            return;
        }
        
        int n = s.size();
        
        for(int i = ind; i < n - 1; i++){
            
            for(int j = i + 1; j < n; j++){
                
                if(s[i] < s[j]){
               		swap(s[i] , s[j]);
                	swapNums(s, k, ans, count + 1, ind + 1);
                	swap(s[i] , s[j]);
                }
            }
        }
    }
    
    
    
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        
        string ans = s;
        
        swapNums(s, k, ans, 0, 0);
        
       
        
        return ans;
    }
};