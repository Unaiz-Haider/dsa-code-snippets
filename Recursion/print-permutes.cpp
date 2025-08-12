// Using extra space i.e frequency

#include <iostream>
#include <vector>
using namespace std;

void permutes(vector<int> &nums, vector<int> &temp, int freq[]){
    
    if(temp.size() >= nums.size()){
        for(int it : temp){
            cout << it; 
        }
        cout << endl;
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            freq[i] = 1;
            temp.push_back(nums[i]);

            permutes(nums, temp, freq);

            freq[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    // Write C++ code here
    vector<int> v = {1,2,3};
    
    vector<int> temp;
    int freq[v.size()] = {0};
    
    permutes(v, temp, freq);

    return 0;
}








// No extra space, just swaps

#include <iostream>
#include <vector>
using namespace std;

void permutes(vector<int> &nums, int ind){
    
    if(ind >= nums.size()){
        for(int it : nums){
            cout << it; 
        }
        cout << endl;
        return;
    }
    
    for(int i = ind; i < nums.size(); i++){

       swap(nums[ind] , nums[i]);

       permutes(nums, ind + 1);

       swap(nums[ind] , nums[i]);
    }
}

int main() {
    // Write C++ code here
    vector<int> v = {1,2,3};
    
    vector<int> temp;
    int freq[v.size()] = {0};
    
    permutes(v, 0);

    return 0;
}