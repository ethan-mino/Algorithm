#include <bits/stdc++.h>
using namespace std;

long long d[100][2]; // d[i][j]는 i자리이고, 끝자리가 j인 이친수 개수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    d[1][0] = 0; d[1][1] = 1;
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }
    cout << d[n][0] + d[n][1];
}   

// xxx0
// xxx1

// 10000 o
// 10001 o
// 10010 o
// 10011 x
// 10100 o 
// 10101 o
// 10110 x
// 10111 x
// 11000 x
// 11001 x
// 11010 x
// 11011 x
// 11100 x
// 11101 x
// 11110 x
// 11111 x