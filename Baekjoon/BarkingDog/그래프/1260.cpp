#include <bits/stdc++.h>
using namespace std;

int vis[1010];
int n, m, st;
void bfs(vector<vector<int>> & adj){
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    fill(vis, vis + 1010, 0);

    queue<int> q;
    q.push(st);
    vis[st] = 1;
    cout << st << " ";

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] != 0) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cout << nxt << " ";
        }
    }
}

void dfs(vector<vector<int>> & adj){
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), greater<>());
    fill(vis, vis + 1010, 0);

    stack<int> s;
    s.push(st);
    
    while(!s.empty()){
        int cur = s.top(); s.pop();

        if(vis[cur] != 0) continue;
        vis[cur] = 1;
        cout << cur << " ";

        for(auto nxt : adj[cur]){
            if(vis[nxt] != 0) continue;
            s.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> st;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj);
    cout << "\n";
    bfs(adj);
}