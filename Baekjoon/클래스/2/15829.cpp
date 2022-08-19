#include <bits/stdc++.h>
using namespace std;

long long mod(int s, int a, int b, int m){
    long long ans = s % m;

    while(b--){ans = ans * a % m;}
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    long long sum = 0;

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        sum +=  mod((c - 96), 31, i, 1234567891);
    }
    
    cout << sum % 1234567891;
}

/*
50
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/