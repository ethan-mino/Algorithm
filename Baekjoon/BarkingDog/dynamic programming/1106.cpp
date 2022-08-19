// Created by 길민호 on 2022/08/13.

#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
int d[1010];   // 메모이제이션을 위한 배열, d[n]은 호텔의 고객을 적어도 n명 늘이기 위해 필요한 홍보 비용의 최솟값

int cost[30];   // cost[i]는 i번째 도시의 홍보 비용
int customer[30];   // customer[i]는 i번째 도시에 홍보할 때 유입되는 고객의 수
int t, c;

// 다이나믹 프로그래밍은 테이블 정의, 점화식 작성, 초기식 정하기로 구성됨.
// 테이블 정의 : d[n]은 호텔의 고객을 적어도 n명 늘이기 위해 필요한 홍보 비용의 최솟값
// 점화식 작성 : d[n] = min(d[n], d[n - i번째 도시에 홍보할 때 유입되는 고객의 수] + 1번째 도시의 홍보 비용)
// 초기식 작성 : 홍보 비용의 최소값을 찾아야하기 때문에, 모두 최대값으로 초기화

// Dynamic Programming Top Down
int dp(int n){  // 호텔의 고객을 적어도 n명 늘리기 위해 투자해야하는 금액의 최솟값
    if(n == 0) return 0;    // 고객 0명을 늘리기 위한 홍보 비용 = 0
    if(d[n] != INF) return d[n];    // 이미 최소 홍보 비용이 계산된 경우 해당 값을 반환
    else{   // 아직 고객을 n명 늘리기 위해 필요한 최소 홍보 비용이 계산되지 않은 경우
        for(int i = 0; i < c; i++){ // 각 도시를 순회하며, 어떤 도시에 순회하는 것이 비용이 가장 적은지 확인
            /*
                예를 들어 10명의 고객을 늘리기 위해 필요한 홍보 비용의 최솟값을 구해야 하는 경우
                1번 도시 : 홍보 비용 5, 유입되는 고객 수 : 3
                2번 도시 : 홍보 비용 4, 유입되는 고객 수 : 2
                3번 도시 : 홍보 비용 3, 유입되는 고객 수 : 1
                이라면,
                7명의 고객을 만들기 위해 필요한 홍보 비용의 최솟값 + 1번 도시의 홍보 비용
                8명의 고객을 만들기 위해 필요한 홍보 비용의 최솟값 + 2번 도시의 홍보 비용
                9명의 고객을 만들기 위해 필요한 홍보 비용의 최솟값 + 3번 도시의 홍보 비용
                중 가장 최솟값을 선택
            */
            if(n - customer[i] >= 0){
                d[n] = min(d[n], dp(n - customer[i]) + cost[i]);
            }else{  // 단, n - customer[i]가 음수인 경우는 예외 처리 해주어야 OutOfBound 예외가 발생하지 않음
                d[n] = min(d[n], dp(customer[i])) ;
            }
        }

        return d[n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> c;

    for(int i =0 ; i < c; i++) cin >> cost[i] >> customer[i];
    fill(d, d + 1010, INF);
    dp(t);
    cout << d[t] << "\n";
}