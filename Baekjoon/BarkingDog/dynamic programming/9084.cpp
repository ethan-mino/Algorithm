// Created by 길민호 on 2022/07/05.

#include <bits/stdc++.h>
using namespace std;

int n;
int coin[21];
int dp[10010];  // dp[i]는 i의 돈을 만드는 모둔

int dynamic(int money){
    //cout << money << "\n";
    if(money == 0) return 1;
    else if (money < 0) return 0;
    else if(dp[money] != 0) return dp[money];
    else{
        for(int i = 0; i < n; i++){
            dp[money] += dynamic(money - coin[i]);
        }

        return dp[money];
    }
}

int factorial(int n){
    if(n <= 1) return 1;
    else return n * factorial(n - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        fill(dp, dp + 10010, 0);

        int m;  cin >> n;
        for(int i = 0; i < n; i++){
            cin >> coin[i];
        }

        cin >> m;
        // 조합 nCr
        // n!
        // (n - r)! * r!
        // n!
        // n - r) !
        cout << dynamic(m) / factorial(n) << "\n";
        for(int i = 0; i <= m; i++) cout << i << " ";
        cout << "\n";

        for(int i = 0; i <= m; i++) cout <<dp[i] << " ";
        cout << "\n";
    }
}

/*
1
1
1
5

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