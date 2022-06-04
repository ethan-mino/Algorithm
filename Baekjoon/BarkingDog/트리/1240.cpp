#include <bits/stdc++.h>
using namespace std;

#define v first
#define d second
#define MAX 1010
int vis[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> linked(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v, dist; cin >> u >> v >> dist;
        linked[u].push_back({v, dist});
        linked[v].push_back({u, dist});
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        fill(vis, vis + MAX, 0);
        queue<int> q;
        q.push(u);
        vis[u] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : linked[cur]){
                if(vis[nxt.v] != 0) continue;
                vis[nxt.v] = vis[cur] + nxt.d;
                q.push(nxt.v);
            }
        }
        cout << vis[v] - 1<< "\n";
    }
}