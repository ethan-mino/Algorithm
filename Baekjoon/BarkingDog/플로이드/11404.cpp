#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001
#define SIZE 101
int dist[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], MAX);
    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int dest = 1; dest <= n; dest++){
                if(st != dest){
                    dist[st][dest] = min(dist[st][dest], dist[st][pass] + dist[pass][dest]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] >= MAX) dist[i][j] = 0;
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}