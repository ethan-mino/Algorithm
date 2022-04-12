#include <bits/stdc++.h>
using namespace std;

int arr[2000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    for(int i = 0; i < n; i++) cout << arr[i] << "\n";
}   
