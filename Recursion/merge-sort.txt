// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int low, int mid, int high){
    
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    
    for(int i = 0; i < temp.size(); i++){
        arr[i + low] = temp[i];
    }
    
}

void mergeSort(vector<int> &arr, int low, int high){
    
    if(low >= high) return;
    
    int mid = (low + high) / 2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    
    merge(arr, low, mid, high);
    
    
    
}
int main() {
    // Write C++ code here
    vector<int> arr = {6,2,4,7,3,2,1};
    
    for(int it : arr)cout<<it<<" ";
    
    cout<<endl;
    
    mergeSort(arr, 0, arr.size()-1);
    
    for(int it : arr)cout<<it<<" ";

    return 0;
}