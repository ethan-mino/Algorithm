#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int accur[2000001] = {};

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        accur[c] += 1;
    }

    int x;
    cin >> x;
    
    int cnt = 0;

    for(int i = 1; i < x; i++){
        if(accur[i] != 0 && accur[x-i] != 0){
            cnt++;
        }
    }

    cout << cnt / 2;
}