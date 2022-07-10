// Created by 길민호 on 2022/07/05.

#include <bits/stdc++.h>
using namespace std;

int d[21][10010]; // d[i][j]는 i번째까지의 코인을 이용하여 금액 j를 만들 수 있는 경우의 수
int coin[21];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        fill(coin, coin + 21, 0);
        fill(&d[0][0], &d[20][10010], 0);

        cin >> n;
        for(int i = 0; i < n; i++) cin >> coin[i];
        int target; cin >> target;

        for(int c = 0; c < n; c++) d[c][0] = 1;
        for(int c = 0; c < n; c++){ // c는 동전의 번호를 의미
            for(int m = coin[c]; m <= target; m++){   // m은 만들고자 하는 금액을 의미
                if(c > 0) d[c][m] += d[c - 1][m];
                d[c][m] += d[c][m - coin[c]];
                // (c - 1번째 까지의 코인을 이용하여 m을 만드는 경우의 수) + (c번째까지의 코인을 이용하여 m - coin[c]를 만드는 경우의 수)
            }
        }

        cout << d[n - 1][target] << "\n";
    }
}

/*
1
5
1 2 4 5 20
20

1
1
20
20

1
2
1 2
5

1
2
1 2
4
*/