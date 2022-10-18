// Created by 길민호 on 2022/10/07.
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int distance(pair<int, int> pos1, pair<int, int> pos2){
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

int main() {

    int t; cin >> t;
    while(t--){
        int vis[110];
        fill(vis, vis + 110, 0);

        int n; cin >> n;
        vector<pair<int, int>> poses;

        for(int x, y, i = 0; i < n + 2; i++){
            cin >> x >> y;
            poses.push_back({x, y});
        }

        vector<int> linked[poses.size()];
        for(int u =0 ; u < poses.size(); u++){
            pair<int, int> pos1 = poses[u];
            for(int v = u + 1 ; v < poses.size(); v++){
                if(u == v) continue;

                pair<int, int> pos2 = poses[v];
                if(distance(pos1, pos2) <= 1000){
                    linked[u].push_back(v);
                    linked[v].push_back(u);
                }
            }
        }

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : linked[cur]){
                if(vis[nxt] != 0) continue;
                q.push(nxt);
                vis[nxt] = 1;
            }
        }

        if(vis[n + 1] != 0) cout << "happy";
        else cout << "sad";
        cout << "\n";
    }
}