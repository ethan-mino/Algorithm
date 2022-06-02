#include <bits/stdc++.h>
using namespace std;

#define MAX 20010
int vis[MAX];

bool isb(vector<vector<int>> linked, int v){
    fill(vis, vis + MAX, 0);

    for(int st = 1; st <= v; st++){
        if(vis[st] == 0){
            queue<int> q;
            q.push(st);
            vis[st] = 1;

            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt : linked[cur]){
                    if(vis[nxt] != 0) {
                        if(vis[nxt] == vis[cur]) return false;
                        else continue;
                    }

                    q.push(nxt);
                    if(vis[cur] == 1) vis[nxt] = 2;
                    else vis[nxt] = 1;
                }
            }
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    while(k--){
        int v, e; cin >> v >> e;
        int cnt = 0;
        vector<vector<int>> linked(v + 1);

        for(int i = 0; i < e; i++){
            int u, v; cin >> u >> v;
            linked[u].push_back(v);
            linked[v].push_back(u);
        }

        bool b = isb(linked, v);

        if(b) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}