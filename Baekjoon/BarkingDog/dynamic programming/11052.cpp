/*시간 초과
#include <bits/stdc++.h>
using namespace std;

int p[1010];
int n;

void back(int start, int remain, int cost){
    if(remain == 0){
        d[start] = max(d[start], cost);
    }else if (remain > 0){
        for(int i = 1; i <= remain; i++){
            back(start, remain - i, cost + p[i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];

    back(n, n, 0);
    cout << d[n] << "\n";
}   
*/

#include <bits/stdc++.h>
using namespace std;
int p[1010], d[1010];   // d[i]는 카드 i개를 구매하기 위해 지불해야하는 금액의 최댓값
int n;

// Top-Down 방식의 dynamic programming
int dp(int n){  // 카드 n개를 구매하기 위해 지불해야하는 금액의 최댓값을 반환하는 함수
    if(d[n] != 0) return d[n];  // 이미 최댓값이 기록되어 있는 경우 해당 값 반환
    else{
        for(int i = 1; i < n; i++)  
            d[n] = max(d[n], (n / i) * dp(i) + dp(n - i * (n/i))); // 가성비가 가장 좋지 않은 카드를 반복하여 구매하고, 남은 카드도 최대한 비싸게 구매
        d[n] = max(d[n], p[n]); // n개의 카드가 들어있는 카드팩의 가격과 비교하여 최댓값 저장
        return d[n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];    // 각 카드팩의 가격 입력 받음

    d[1] = p[1];  // 초기값 지정
    cout << dp(n) << "\n";  // 카드 n개를 구매하기 위해 지불해야하는 금액의 최댓값 계산
}   

/*
4
1 4 97 4
-> 98

9 
10 30 1 1 1 1 1 1 1
-> 130
*/
