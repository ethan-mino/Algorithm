#include <bits/stdc++.h>
using namespace std;

int vis[1010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            ans++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                
                for(auto nxt : linked[cur]){
                    if(vis[nxt] != 0) continue;
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }

    cout << ans << "\n";
}