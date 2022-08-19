#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100000];

bool cmp(const pair<int, int> p1, const pair<int, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
}
