#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
int d[101];
int pre[10], nxt[10];   // pre[j]는 j로 끝나는 N - 1 단계의 계단 수의 개수
                        // nxt[j]는 j로 끝나는 N 단계의 계단 수의 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    d[1] = 9;   // 초기값
    for(int i = 1; i < 10; i++) pre[i] = 1; // 초기값

    // Bottom-Up 방식의 dynamic programming
    for(int i = 2; i <= n; i++){      
        for(int j = 0; j <= 9; j++){
            if(j == 0) nxt[j] = pre[j + 1]; // 0으로 끝나는 N 단계의 계단 수는 1로 끝나는 N - 1 단계의 계단 
            else if(j == 9) nxt[j] = pre[j - 1];    // 9로 끝나는 N 단계의 계단 수는 8로 끝나는 N - 1 단계의 계단 수
            // pre[j - 1], pre[j + 1] 모두 1000000000 보다 작기 때문에 % MOD 해주지 않아도 됨
            else nxt[j] = (pre[j - 1] + pre[j + 1]) % MOD; // i(1 ~ 8)로 끝나는 N 단계의 계단 수는 pre[i - 1] + pre [i + 1]
            
            d[i] = (d[i] + nxt[j]) % MOD;
        }
        
        memcpy(pre, nxt, sizeof(nxt));  // nxt는 pre가 됨
    }

    cout << d[n]<< "\n";
}   

// n0 + (n0 + n2) + (n1 + n3) + ... + (n7 + n8) + n9
// nxt[0] + nxt[1] + nxt[2] + nxt[3] + ... +  nxt[9] 
