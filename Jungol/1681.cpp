// Created by SSAFY on 2022-08-03.

#include <bits/stdc++.h>
using namespace std;

#define INF 50000
#define SIZE 20

int dist[SIZE][SIZE];
int s[SIZE][SIZE];
bool selected[SIZE];
int n, ans = INT_MAX;

void back(int th, int pre, int d){
    if(th == n + 1){
        d += dist[pre][1];
        if(ans > d) ans = d;
    }else if(d < ans){
        for(int cur = 2; cur <= n; cur++){
            if(!selected[cur]){
                selected[cur] = true;
                back(th + 1, cur, d + dist[pre][cur]);
                selected[cur] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j) s[i][j] = 0;
            cin >> dist[i][j];
            if(dist[i][j] == 0) dist[i][j] = INF;
        }

    back(2, 1, 0);
    cout << ans << "\n";
}