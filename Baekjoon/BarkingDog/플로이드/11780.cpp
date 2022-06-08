#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define SIZE 101

int dist[SIZE][SIZE];
int nxt[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    fill(&nxt[0][0], &nxt[SIZE - 1][SIZE], INF);

    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(dist[u][v] >  w){
            dist[u][v] = w;
            nxt[u][v] = v;
        }
    }


    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d){
                    dist[st][en] = d;
                    nxt[st][en] = nxt[st][pass];
                }
            }
        }
    }

    for(int st = 1; st <= n; st++){
        for(int en = 1; en <= n; en++){
            if(dist[st][en] == INF) dist[st][en] = 0;
            cout << dist[st][en] << " ";
        }
        cout << "\n";
    }

    for(int st = 1; st <= n; st++){
        for(int en = 1; en <= n; en++){
            if(nxt[st][en] == INF) cout << 0;
            else{
                vector<int> path;
                path.push_back(st);
                int cur = nxt[st][en];
                while(cur != en){
                    path.push_back(cur);    
                    cur = nxt[cur][en];
                }
                path.push_back(cur);
                cout << path.size() << " ";
                for(auto p : path) cout << p << " ";
            }
            cout << "\n";
        }
    }
}