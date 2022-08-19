#include <bits/stdc++.h>
using namespace std;

int arr[10010], d[10010];   // d[i]는 i번째 포도주까지 시식했을 때의 최대 포도주 양

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    d[1] = arr[1]; d[2] = arr[1] + arr[2]; // 초기값
    for(int i = 3; i <= n; i++)
        d[i] = max({d[i - 3] + arr[i - 1]+ arr[i], d[i - 2] + arr[i], d[i - 1]});

    cout << d[n];
}   

/*
6
6 10 13 9 8 10000
-> 10031

6
15 10 13 9 8 10000
-> 10037

3
15 10 13
-> 28
*/
