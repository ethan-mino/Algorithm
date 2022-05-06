#include <bits/stdc++.h>
using namespace std;

#define MOD 15746
int d[1000010]; // d[i]는 길이가 i인 모든 2진 수열의 개수 % 15746

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i - 2] + d[i - 1]) % MOD;
    cout << d[n] % MOD;
}   