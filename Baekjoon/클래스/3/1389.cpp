#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);
    
    for(int i = 0; i < m ; i++){
        pair<int, int> r; cin >> r.a >> r.b;
        linked[r.a].push_back(r.b);
        linked[r.b].push_back(r.a);
    }

    pair<int, int> ans = {0, INT_MAX};
    for(int i = 1 ; i <= n; i++){
        int vis[101];
        fill(vis, vis + 101, 0);
        queue<int> q;
        
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int j = 0; j < linked[cur].size(); j++){
                int nx = linked[cur][j];
                if(vis[nx] != 0) continue;
                q.push(nx);
                vis[nx] = vis[cur] + 1;
            }
        }

        int s = 0;
        for(int j = 1; j <= n; j++) if(i != j) s+= vis[j] - 1;
        if(ans.second > s || (ans.second == s && ans.first > i)) ans = {i, s};
    }

    cout << ans.first;
}   
