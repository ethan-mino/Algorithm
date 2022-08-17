#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
#define ZERO 1000000
int d[2000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    d[ZERO] = 0; d[ZERO + 1] = 1;
    for(int i = ZERO + 2; i <= abs(ZERO + n); i++)
        d[i] = (d[i - 1] + d[i - 2]) % MOD;
    
    for(int i = ZERO - 1; i >= ZERO + abs(n) * -1; i--)
        d[i] = (d[i + 2] - d[i + 1]) % MOD;
        
    if(d[ZERO + n] > 0) cout << 1 << "\n";
    else if (d[ZERO + n] == 0) cout << 0 << "\n";
    else cout << -1 << "\n";
    cout << abs(d[ZERO + n]) % MOD;
}   