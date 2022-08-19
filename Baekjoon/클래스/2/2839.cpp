#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int m = 2000;
    for(int i = 0; i <= n/5; i++){
        if((n - (5*i)) % 3 == 0 && i + ((n - (5*i)) / 3) < m){
            m = i + ((n - (5*i)) / 3);
        }
    }
    
    if(m == 2000) cout << -1;
    else cout << m;
}