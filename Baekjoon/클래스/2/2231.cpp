#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        int j = 0;
        int sum = 0;

        while(i / (int) pow(10, j)> 0){
            sum += i / (int) pow(10, j) % 10;
            j++;
        }
        if(sum + i == n){
            cout << i; return 0;
        }
    }
    cout << 0;
}

// 3736
// 3739 / 1000 -> 3 % 10 -> 3
// 3739 / 100 -> 37 % 10 -> 7
// 3739 / 10 -> 373 % 10 -> 3


// 180 / 100 -> 1 % 10 -> 1
// 180 / 10 -> 18 % 10 -> 8
