#include <bits/stdc++.h>
using namespace std;

long long a, b, ans = INT_MAX;

void back(int th, long long n){
    if(n == b){
        ans = min(ans, (long long) th - 1);
    }else if(n < b){
        back(th + 1, 2 * n);
        back(th + 1, 10 * n + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    back(1, a);
    cout << ((ans == INT_MAX) ? -1 : ans + 1);
}   