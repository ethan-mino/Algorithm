// Created by 길민호 on 2022/07/05.

#include <bits/stdc++.h>
using namespace std;

int d[10010]; // d[i][j]는 i번째까지의 코인을 이용하여 금액 j를 만들 수 있는 경우의 수
int coin[21];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        fill(coin, coin + 21, 0);
        fill(d, d + 10010, 0);

        cin >> n;
        for(int i = 0; i < n; i++) cin >> coin[i];
        int target; cin >> target;

        d[0] = 0;
        d[coin[0]] = 1;
        for(int money = 1; money <= target; money++){
            for(int j = 0; j < n; j++){
                if(money - coin[j] > 0)
                    d[money] += d[money - coin[j]];
            }
        }

        for(int i =1 ; i <= target; i++)
            cout << d[i] << " ";
        cout << "\n\n";

        cout << d[target] << "\n";
    }
}

/*
1
2
1 2
1000

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