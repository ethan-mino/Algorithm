// Created by 길민호 on 2022/07/04.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 16
#define INF 20000000

int weight[SIZE][SIZE];
int d[SIZE][1<<SIZE];
int st = 0;
int n;

int TSP(int cur, int visited){
    int &ret = d[cur][visited];
    if(ret != 0) return ret;

    if(visited == (1 << n) - 1){
        if(weight[cur][st] != 0)
            ret = weight[cur][st];
        else ret = INF;
        return ret;
    }

    ret = INF;
    for(int nx = 0; nx < n; nx++){
        if(cur == nx || weight[cur][nx] == 0) continue;
        if(visited & 1 << nx) continue;

        ret = min(ret, TSP(nx, visited | (1 << nx)) + weight[cur][nx]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int u = 0; u < n; u++)
        for(int v = 0; v < n; v++)
            cin >> weight[u][v];

    cout << TSP(st, 1) << "\n";
}