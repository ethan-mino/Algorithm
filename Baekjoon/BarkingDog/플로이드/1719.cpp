// Created by 길민호 on 2022/06/09.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 201
#define INF 100000000
int dist[201][201];
int nxt[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 1; i <= n; i++) nxt[i][i] = 0;

    for(int i =0 ; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(dist[u][v] > w){
            dist[u][v] = w; dist[v][u] = w;
            nxt[u][v] = v; nxt[v][u] = u;
        }
    }

    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d)  {
                    dist[st][en] = d;
                    nxt[st][en] = nxt[st][pass];
                }
            }
        }
    }

    for(int st = 1; st <= n; st++){
        for(int en = 1; en <= n; en++){
            if(nxt[st][en] == 0) cout << "-";
            else cout << nxt[st][en];
            cout << " ";
        }
        cout << "\n";
    }
}
