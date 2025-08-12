// All combos
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    
void genCombs(vector<string> &ans, string &temp, int n){
        
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('0');
        genCombs(ans, temp, n);
        temp.pop_back();
        
        temp.push_back('1');
        genCombs(ans, temp, n);
        temp.pop_back();
    }
    
vector<string> generateStrings(int n){
        
        vector<string> ans;
        string temp;
        
        genCombs(ans, temp, n);
        
        for(auto it : ans){
            cout << it << " ";
        }
        
        return ans;
}

int main() {
    // Write C++ code here
    int n = 3;
    
    generateStrings(n);
    
    //ex n = 3
    // 000, 001, 010, 100, 110, 111

    return 0;
}





// No consecutive 1s are printed
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    
void genCombs(vector<string> &ans, string &temp, int n){
        
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('0');
        genCombs(ans, temp, n);
        temp.pop_back();
        
        if(temp.back() == '0' || temp.empty()){
            temp.push_back('1');
            genCombs(ans, temp, n);
            temp.pop_back();
        }
    }
    
vector<string> generateStrings(int n){
        
        vector<string> ans;
        string temp;
        
        genCombs(ans, temp, n);
        
        for(auto it : ans){
            cout << it << " ";
        }
        
        return ans;
}

int main() {
    
    // generate strings without consecutive ones '1s'
    int n = 3;
    
    generateStrings(n);
    
    //ex n = 3
    // 000, 001, 010, 100, 101

    return 0;
}