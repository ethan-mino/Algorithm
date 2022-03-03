#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll factorial(int n){
    if(n <= 1) return 1;
    else return n * factorial(n-1);
}

ll binomial(int n, int k){
    if(k < 0 || k > n)  return 0;
    else return factorial(n) / (factorial(k) * (factorial(n-k)));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    cout << binomial(n, k);
}
