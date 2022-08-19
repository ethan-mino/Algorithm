#include <bits/stdc++.h>
using namespace std;

#define INF 5000000
#define SIZE 401
int dist[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e; cin >> v >> e;
    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    for(int i = 1; i <= v; i++) dist[i][i] = 0;

    for(int i = 1; i <= e; i++){
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
        
    for(int pass = 1; pass <= v; pass++){
        for(int st = 1; st <= v; st++){
            for(int en = 1; en <= v; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d) dist[st][en] = d;
            }
        }
    }

    int ans = INT_MAX;
    for(int st = 1; st <= v; st++){
        for(int en = 1; en <= v; en++){
            if(st != en){
                ans = min(ans, dist[st][en] + dist[en][st]);
            }
        }
    }

    if(ans >= INF) cout << - 1 << "\n";
    else cout << ans << "\n";
}

// 1. 무방향 그래프
// 2. 운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력한다.
// 3. (a, b) 쌍이 같은 도로가 여러 번 주어지지 않는다.