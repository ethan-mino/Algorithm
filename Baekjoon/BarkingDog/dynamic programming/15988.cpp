#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009
long long d[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n; cin >> t;

    d[1] = 1; d[2] = 2; d[3] = 4;   // 초기값
    for(int i = 4 ; i <= 1000000; i++)
        d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % MOD;  // 테이블 채우기

    while(t--){ // 각 테스트 케이스마다 n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력
        cin >> n;
        cout << d[n] << "\n";   
    }
}  

/*
1
1000000
-> 810017797

1
10000
-> 795055102
*/
