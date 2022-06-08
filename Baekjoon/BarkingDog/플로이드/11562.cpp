#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define SIZE 251
#define INF 10000000

int dist[SIZE][SIZE];
int nxt[SIZE][SIZE];
int conn[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, b; cin >> u >> v >> b;
        conn[u][v] = 1;
        if(b == 1) conn[v][u] = 1;
    }

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    for(int i = 1; i <= n; i++) conn[i][i] = 1;
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 1; i <= n; i++) nxt[i][i] = i;

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            if(conn[u][v] == 1 && dist[u][v] == INF){
                nxt[u][v] = v; nxt[v][u] = u;
                dist[u][v] = 1;
                if(conn[v][u] == 1) dist[v][u] = 1; // 양방향인 경우
                else dist[v][u] = 500;
            }
        }
    }

    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d) {
                    dist[st][en] = d;
                    nxt[st][en] = nxt[st][pass];
                }
            }
        }
    }

    cin >> k;
    while(k--){
        int s, e; cin >> s >> e;
        int cnt = 0;    // 일방통행인 길을 양방향 통행으로 바꿔야할 길의 개수
        int pr = s;
        int nx = nxt[s][e];
        while(nx != e){
            if(conn[pr][nx] != 1) cnt++;
            pr = nx;
            nx = nxt[nx][e];
        }
        if(conn[pr][nx] != 1) cnt++;
        cout << cnt << "\n";
    }
}

/*
4 3
1 2 1
2 3 1
3 4 1
7
1 1
1 2
2 1
1 4
4 1
2 3
4 3
-> 0 0 0 0 0 0 0

4 3
1 2 0
2 3 1
3 4 0
5
1 1
2 2
3 3
4 4
4 3
-> 0 0 0 0 1

4 4
1 2 0
2 3 1
3 4 1
4 2 0
1
1 4
 -> 0
*/