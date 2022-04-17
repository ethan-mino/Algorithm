#include <bits/stdc++.h>
using namespace std;

long long d[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int i = 1; i < 4; i++) d[i] = 1;

    for(int i = 4; i <= 100; i++){
        d[i] = d[i - 2] + d[i - 3];
    }

    while(t--){
        int n; cin >> n;
        cout << d[n] << "\n";
    }
}   
