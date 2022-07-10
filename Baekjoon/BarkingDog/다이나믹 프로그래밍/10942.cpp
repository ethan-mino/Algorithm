// Created by 길민호 on 2022/07/10.

#include <bits/stdc++.h>
using namespace std;

#define DP_INIT -1
#define PALINDROME 1
#define NOT_PALINDROME 0

int d[2020][2020];
int seq[2020];

int dp(int st, int en){
    if(d[st][en] != DP_INIT) return d[st][en];
    else{
        if(st == en){
            d[st][en] = PALINDROME;
        }else if(seq[st] != seq[en]){
            d[st][en] = NOT_PALINDROME;
        }else{
            if(st +1 == en) d[st][en] = PALINDROME;
            else if(dp(st + 1, en - 1)) d[st][en] = PALINDROME;
            else d[st][en] = NOT_PALINDROME;
        }

        return d[st][en];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> seq[i];

    fill(&d[0][0], &d[n - 1][n], DP_INIT);
    for(int st = 0; st < n; st++) d[st][st] = PALINDROME;

    int m; cin >> m;

    for(int i = 0; i < m; i++){
        int s, e; cin >> s >> e;
        cout << dp(s - 1, e - 1) << "\n";
    }
}

/*
2
1 1
1
1 2
*/

/*

*/