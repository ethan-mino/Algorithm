#include <bits/stdc++.h>
using namespace std;

int vis[501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> adj2(n + 1);

    adj2[1] = adj[1];
    for(int i = 0; i < adj[1].size(); i++){
        adj2[adj[1][i]] = adj[adj[1][i]];
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj2[cur]){
            if(vis[nxt] != 0) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(vis[i] != 0) 
            ans++;
    cout << ans - 1<< "\n"; 
}