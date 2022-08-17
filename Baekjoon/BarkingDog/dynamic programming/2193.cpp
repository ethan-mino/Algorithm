#include <bits/stdc++.h>
using namespace std;

long long d[100][2]; // d[i][j]는 i자리이고, 끝자리가 j인 이친수의 개수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    d[1][0] = 0; d[1][1] = 1;   // 초기값 정하기
    
    for(int i = 2; i <= n; i++){    // 테이블 채우기
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    cout << d[n][0] + d[n][1];
}   
