#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define SIZE 251
#define INF 10000000

int dist[SIZE][SIZE];   // dist[u][v]는 u와 v 사이의 최단 거리
int nxt[SIZE][SIZE];    // nxt[u][v]는 u에서 v간의 최단 경로에서, u 다음 정점의 번호
bool conn[SIZE][SIZE]; // conn[u][v]는 u와 v 사이에 간선이 존재하는지 나타냄

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, b; cin >> u >> v >> b;
        conn[u][v] = true;
        if(b == 1) conn[v][u] = true;  // 영방향인 경우
    }

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);  // 최단 거리 배열을 INF로 설정
    for(int i = 1; i <= n; i++) conn[i][i] = true;  // 동일한 정점간의 간선이 존재한다고 설정
    for(int i = 1; i <= n; i++) dist[i][i] = 0; // 동일한 정점간의 거리는 0
    for(int i = 1; i <= n; i++) nxt[i][i] = i;  // u에서 u로 이동할 때, u 다음 정점은 u

    for(int u = 1; u <= n; u++){    // 각 간선을 양방향으로 수정하고, 기존에 없던 방향의 비용을 높게 설정해줌
        for(int v = 1; v <= n; v++){
            if(conn[u][v] == true){ // 존재하는 간선인 경우
                nxt[u][v] = v; nxt[v][u] = u;
                dist[u][v] = 1; // 간선의 비용을 1로 설정
                if(conn[v][u] == true) dist[v][u] = 1; // 양방향인 경우
                else dist[v][u] = 500;  // 기존에 없던 방향의 비용을 높게 설정
            }
        }
    }

    for(int pass = 1; pass <= n; pass++){   // 플로이드 알고리즘 수행
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
        int pr = s; // s에서 e로의 경로상에서 이전 정점
        int nx = nxt[s][e]; // 다음 정점
        while(nx != e){ // nx가 도착 지점이 될 때까지 반복
            if(conn[pr][nx] != true) cnt++; // 기존에 없던 방향인 경우 cnt 증가
            pr = nx;
            nx = nxt[nx][e];
        }
        if(conn[pr][nx] != true) cnt++; // 기존에 없던 방향인 경우 cnt 증가
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