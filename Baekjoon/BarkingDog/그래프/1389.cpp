#include <bits/stdc++.h>
using namespace std;

#define idx first
#define v second

int vis[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    pair<int, int> ans = {-1, INT_MAX};
    for(int i = 1; i <= n; i++){
        fill(vis, vis + 101, 0);
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(auto nxt : linked[cur]){
                if(vis[nxt] != 0) continue;
                q.push(nxt);
                vis[nxt] = vis[cur] + 1; 
            }
        }
        
        int k = accumulate(vis, vis + 101, 0) - n;
        if(ans.v > k)
            ans = {i, k};
    }
    cout << ans.idx << "\n";
}