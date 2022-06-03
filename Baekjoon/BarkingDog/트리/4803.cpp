#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 1;
    while(true){
        int n, m; cin >> n >> m;
        if(!n && !m) break;
        vector<vector<int>> linked (n + 1);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            linked[u].push_back(v);
            linked[v].push_back(u);
        }

        int vis[501];
        fill(vis, vis + 501, 0);
        int ans = 0;
        for(int st = 1; st <= n; st++){
            if(vis[st] == 0){
                queue<int> q;
                q.push(st);
                vis[st] = 1;

                bool istree = true;
                while(!q.empty()){
                    int cur = q.front(); q.pop();

                    for(auto nxt : linked[cur]){
                        if(vis[nxt] != 0 && vis[nxt] != vis[cur] - 1) {
                            istree = false;
                            break;
                        }
                        
                        if(vis[nxt] != 0) continue;
                        vis[nxt] = vis[cur] + 1;
                        q.push(nxt);
                    }
                }

                if(istree) ans++;
            }
        }
        cout << "Case " << c++ << ": ";
        if(ans > 1)
            cout << "A forest of " << ans << " trees.";
        else if(ans == 1)
            cout << "There is one tree.";
        else 
            cout << "No trees.";
        cout << "\n";
    }
}

/*
6 6
1 2
2 3
1 3
4 5
5 6
6 4
0 0
*/