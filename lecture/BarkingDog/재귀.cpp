#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n == 0) return 0;
    else return n + sum(n-1);
}

void printNum(int n){
    if(n < 0) return;
    cout << n << "\n";
    printNum(n-1);
}

using ll = long long;

ll mod(int a, int b, int m){
    ll ans = 1;
    while(b--) {ans = ans * a % m;}
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //printNum(10);
    //cout << mod(234236116, 29123, 10) << "\n";
    cout << mod(2, 5, 3) << "\n";
}