// For All subsequences sum

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void sequence(vector<int> &arr, vector<int> &newArray, int sum, int i, int n, int k){
    
    if(i >= n){
        if(sum == k){
            for(int num : newArray){
                cout << num;
            }
            cout<<endl;
        }
       
        return;
    }
    
    newArray.push_back(arr[i]);
    sum += arr[i];
    sequence(arr, newArray, sum, i+1, n, k);
    
    newArray.pop_back();
    sum -= arr[i];
    sequence(arr, newArray, sum, i+1, n, k);
    
    return;
    
}
int main() {
    // Write C++ code here
    
    vector<int> temp = {1, 2, 3, 1, -1};
    
    int sum = 0;
    vector<int> ans;
    sequence(temp, ans, sum, 0, temp.size(), 0);
    

    return 0;
}












// For only one subsequence sum

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool sequence(vector<int> &arr, vector<int> &newArray, int sum, int i, int n, int k){
    
    if(i >= n){
        if(sum == k){
            for(int num : newArray){
                cout << num;
            }
            cout<<endl;
            return true;
        }
       
        return false;
    }
    
    newArray.push_back(arr[i]);
    sum += arr[i];
    if(sequence(arr, newArray, sum, i+1, n, k)) return true;
    
    newArray.pop_back();
    sum -= arr[i];
    if(sequence(arr, newArray, sum, i+1, n, k)) return true;
    
    return false;
    
}
int main() {
    // Write C++ code here
    
    vector<int> temp = {1, 2, 3, 1, -1};
    
    int sum = 0;
    vector<int> ans;
    sequence(temp, ans, sum, 0, temp.size(), 3);
    

    return 0;
}












// Count the number of subsequences equal to sum

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int sequence(vector<int> &arr, vector<int> &newArray, int sum, int i, int n, int k){
    
    if(i >= n){
        if(sum == k){
            for(auto num:newArray)cout<<num;
            cout<<endl;
            return 1;
        }
        return 0;
    }
    
    newArray.push_back(arr[i]);
    sum += arr[i];
    int left = sequence(arr, newArray, sum, i+1, n, k);
    
    newArray.pop_back();
    sum -= arr[i];
    int right = sequence(arr, newArray, sum, i+1, n, k);
    
    return left + right;
    
}
int main() {
    // Write C++ code here
    
    vector<int> temp = {1, 2, 3, -1};
    
    int sum = 0;
    vector<int> ans;
   
   int count = sequence(temp, ans, sum, 0, temp.size(), 6);
   
   cout<<"This is the count "<<count;
    

    return 0;
}