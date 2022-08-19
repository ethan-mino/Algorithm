#include <bits/stdc++.h>
using namespace std;

int d[41];  // d[i]는 좌석이 i개 일때, 가능한 좌석 배치의 수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    int vip[40];
    for(int i = 0; i < m; i++) cin >> vip[i];   // vip 좌석 입력 받음

    d[0] = 1; d[1] = 1; d[2] = 2;   // 초기값
    for(int i = 3; i <= 40; i++)    // 테이블 채움
        d[i] = d[i - 1] + d[i - 2];

    if(m > 0){  // vip 좌석이 있는 경우
        vector<int> interval;

        interval.push_back(vip[0] - 1); // 첫번째 vip와 첫번째 좌석 사이 좌석의 개수
        interval.push_back(n - vip[m - 1]); // 마지막 vip와 마지막 좌석 사이 좌석의 개수

        for(int i = 0; i < m - 1; i++)
            interval.push_back(vip[i + 1] - vip[i] - 1);    // vip 사이 좌석의 개수

        int ans = 1;    
        for(auto i : interval) ans *= d[i]; // 각 좌석의 개수에 따른 가능한 좌석 배치의 개수를 곱해줌
        cout << ans;
    }else{  // vip 좌석이 없는 s경우
        cout << d[n];
    }
}   

/*
9 0
-> 55

40 3
10
20
30
-> 14807375%

3 2
1 2
-> 1
*/