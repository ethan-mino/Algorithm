#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
#define SIZE 101
int dist[SIZE][SIZE];
int item[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r; cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> item[i];
    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 0; i < r; i++){
        int u , v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d) dist[st][en] = d;
            }
        }
    }

    int ans = INT_MIN;
    for(int v = 1; v <= n; v++){
        int cnt = 0;
        for(int nxt  = 1; nxt <= n; nxt++){
            if(dist[v][nxt] <= m) cnt += item[nxt];
        }
        ans = max(ans, cnt);
    }

    if(ans == INT_MIN) cout << 0 << "\n";
    cout << ans << "\n";
}