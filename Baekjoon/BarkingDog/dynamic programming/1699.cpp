// Created by 길민호 on 2022/07/05.

#include <bits/stdc++.h>
using namespace std;

vector<int> sq;
int d[100010];

int LS(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(d[n] != 0) return d[n];


    auto idx = lower_bound(sq.begin(), sq.end(), n) - sq.begin();
    if(sq[idx] == n) d[n] = 1;
    else {
        d[n] = INT_MAX;
        for(int i = 0; i < idx; i++)
            d[n] = min(d[n], LS(sq[i]) + LS(n - sq[i]));
    }

    return d[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int cur = 1;
    while(cur * cur <= n){
        sq.push_back(cur * cur);
        cur++;
    }

    cout << LS(n) << "\n";
}

/*
1 1
2 2
3 3
4 1
5 2
6 3
7 4
8 2
9 1
10 2
11 3
12 4
13 2
14 3
15 4
16 1
17 2
18 2

*/