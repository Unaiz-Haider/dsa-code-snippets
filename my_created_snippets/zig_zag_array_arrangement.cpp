
class Solution {
  public:
    void zigZag(vector<int> &arr) {
        // code here
        int i = 0;
        
        for(int j = 1; j < arr.size(); j++){
            
            if(j % 2 == 1){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
            else{
                if(arr[i] < arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
            i++;
        }
        return;
    }
};
