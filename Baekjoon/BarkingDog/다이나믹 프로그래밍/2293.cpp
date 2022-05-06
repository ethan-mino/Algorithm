#include <bits/stdc++.h>
using namespace std;

int coin[101], d[10010];    // d[i]는 가치의 합이 i원인 경우의 수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> coin[i];
    
    sort(coin, coin + n);
    d[coin[0]] = 1;
    for(int i = 1; i <= n; i++){

    }
}   

/*
1

1 1
2


*/