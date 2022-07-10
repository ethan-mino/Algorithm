// Created by 길민호 on 2022/07/10.

#include <bits/stdc++.h>
using namespace std;

#define SK 0
#define CY 1

bool d[1010];   // d[i]는 돌이 i개 있을 때, 먼저 시작하는 사람이 이기는 지 아닌지 나타냄.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    d[1] = true; d[2] = false; d[3] = true;
    for(int i = 4; i <= n; i++){
        if(d[i - 3] && d[i - 1]) d[i] = false;
        else d[i] = true;
    }

    if(d[n]) cout << "SK";
    else cout << "CY";
}
