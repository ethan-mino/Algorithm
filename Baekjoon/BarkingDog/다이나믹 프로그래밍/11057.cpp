#include <bits/stdc++.h>
using namespace std;

#define MOD 10007
int d[10][1010];    // d[i][j]는 길이가 N이고, i로 끝나는 오르막 수의 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < 10; i++) d[i][1] = 1;    // 초기값 지정

    for(int i = 2; i <= n; i++){    // 테이블 채우기
        for(int j = 0; j < 10; j++){
            for(int k = j; k >= 0; k--)
                d[j][i] += d[k][i - 1] % MOD;   // d[j][i]는 길이가 N - 1이고, j보다 작거나 같은 오르막 개수의 합
            d[j][i] %= MOD;
        }
    }

    int ans = 0;
    for(int j = 0; j < 10; j++) ans += d[j][n] % MOD;   // 길이가 N이고, j로 끝나는 오르막 수의 총합
    cout << ans % MOD << "\n";
}   