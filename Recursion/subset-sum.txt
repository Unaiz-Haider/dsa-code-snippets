#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void subset(vector<int> &v, int n, int ind, vector<int> &ans, int sum){

    if(ind >= n){
        ans.push_back(sum);;
        return;
    }

    subset(v, n, ind + 1, ans, sum + v[ind]);

    subset(v, n, ind + 1, ans, sum);

    return;
}

int main(){

    vector<int> v = {1,2,3};

    vector<int> ans;
    int sum = 0;

    subset(v, v.size(), 0, ans, sum);
    
    sort(ans.begin(), ans.end());

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;

}