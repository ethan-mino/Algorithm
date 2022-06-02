#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int vis[MAX];

int bfs(vector<vector<int>> linked, int st){
    fill(vis, vis + MAX, 0);
    queue<int> q;
    vis[st] = 1;
    q.push(st);

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : linked[cur]){
            if(vis[nxt] != 0) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    vector<vector<int>> out(n + 1);
    vector<vector<int>> in(n + 1);

    while(m--){
        int u, v; cin >> u >> v;
        out[u].push_back(v);
        in[v].push_back(u);
    }

    int ans = 0;
    
    for(int st = 1; st <= n; st++){
        int big = bfs(in, st);
        int small = bfs(out, st);
        if(big > (n - ((n + 1) / 2)) || small > (((n + 1)/2) - 1)) ans++;
    }

    cout << ans << "\n";
}

/*
5 4
1 2
2 3
3 4
4 5
-> 4

4 3
1 2
2 3
3 4

*/