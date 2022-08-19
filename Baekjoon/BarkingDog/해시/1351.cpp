#include <bits/stdc++.h>
using namespace std;

long long n, p, q;
map<long, long> m;
long long dp(long long n){
    if(n == 0) return 1;
    else if(m[n] != 0) return m[n];
    else{
        m[n] = dp(floor(n / p)) + dp(floor(n / q));
        return m[n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> q;

    cout << dp(n) << "\n";
}   