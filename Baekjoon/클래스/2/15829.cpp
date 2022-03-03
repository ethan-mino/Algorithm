#include <bits/stdc++.h>
using namespace std;

long long mod(int n){
    long long ans = 1;
    while(n--){
        ans = ans * 31 % 1234567891;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        sum += (c - 96) * mod(i);
    }
    cout << sum;
}

/*
50
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/