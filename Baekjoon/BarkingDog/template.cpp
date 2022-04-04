#include <bits/stdc++.h>
using namespace std;

void pv(string desc, vector<int> arr){
    cout << desc << " : ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void print1(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void printVec1(vector<int>& v){
    for(auto c : v) cout << c << " ";
    cout << "\n";
}

void printVec2(vector<vector<int>>& v){
    cout << "\n";
    for(auto t : v){
        for(auto c : t) cout << c << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

}   
