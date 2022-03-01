#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod(ll a, ll b, ll c){
    if(b == 0)
        return a % c;
    else{
        ll ans = 1;

        const int NUM = 1024;

        ll n = b / NUM;
        if(n != 0){
            ll d = mod(a, n, c);
            for(int i = 0; i < NUM; i++) ans = ans * d % c;
        }

        for(int i = 0; i < (b % NUM); i++) ans = ans * a % c;
        return ans;
    }
}

ll mod2(int a, int b, int m){
    if(b == 1) return a % m;
    
    ll val = mod2(a, b/2, m);
    val = val * val % m;

    if(b&1) return val * a % m;
    return val;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << mod2(a, b, c) << "\n";
}

/*
217483647 217483647 217483647
217483512 217453647 211233647
217483512 1 211233647
217483512 217453647 1024
10 3 3

2 9 3
2 8 3

2 4 3
2 2 3
*/