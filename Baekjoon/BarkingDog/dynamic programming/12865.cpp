#include <bits/stdc++.h>
using namespace std;

int w[101], v[101];
int d[100010], temp[100010];  // d[i]는 무게가 i일 때, 배낭에 넣을 수 있는 가치의 최댓값
int n, k; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;  // n, k 입력 받음
    for(int i = 1 ; i <= n; i++) cin >> w[i] >> v[i]; // 무게와 가치 입력 받음

    for(int i = 1; i <= n; i++){ // i는 물건의 번호를 나타냄 (1 ~ n)
        memcpy(temp, d, sizeof(temp));

        for(int j = 0; j <= k; j++){    // j는 무게를 나타냄
            // i번째 물건을 무게가 j(0 ≤ j ≤ k)인 배낭에 넣어보고, 무게가 j + w[i]인 배낭도 가치가 최대가 되는지 확인
            if(j + w[i] <= k)   // 무게가 j인 배낭에 무게가 w[i]인 물건을 넣어도 k보다 무게가 많이 나가지 않는 경우
                temp[j + w[i]] = max(temp[j + w[i]], d[j] + v[i]);  
        }
        for(int j = 0; j <= k; j++) d[j] = temp[j]; // d[i] 갱신
    }

    cout << d[k];
}   

/* 
7 100
7 4
8 6
9 8
10 8
10 9
50 1
100 10
-> 36
*/


