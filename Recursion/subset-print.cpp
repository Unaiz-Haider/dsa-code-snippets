// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void subsets(vector<int> &v, int ind, vector<int> &temp, vector<vector<int>> &ans){
    
    if(ind >= v.size()){
        for(auto it : temp){
            cout << it << " ";
            }
        cout<<endl;
        return;
    }
    
    temp.push_back(v[ind]);
    subsets(v, ind + 1, temp, ans);
    
    temp.pop_back();
    subsets(v, ind + 1, temp, ans);
}

int main() {
    // Write C++ code here
    vector<int> v = { 1,2,3};
    vector<int> temp;
    
    vector<vector<int>> ans;
    
    subsets(v, 0, temp, ans);
    
    

    return 0;
}