// Created by 길민호 on 2022/06/21.
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define SIZE 1010
#define w first
#define v second

int dist[SIZE];
int pre[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    fill(dist, dist + SIZE, INF);

    vector<vector<pair<int, int>>> linked(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        linked[u].push_back({w, v});
    }

    int st, en; cin >> st >> en;

    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;


    dist[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();
        if(dist[cur.v] != cur.w) continue;

        for(auto nxt : linked[cur.v]){
            if(dist[nxt.v] > dist[cur.v] + nxt.w){
                dist[nxt.v] = dist[cur.v] + nxt.w;  // cur.v -> nxt.v
                pre[nxt.v] = cur.v;
                pq.push({dist[nxt.v], nxt.v});
            }
        }
    }
    vector<int> path;

    cout << dist[en] << "\n";
    int cur = en;
    path.push_back(cur);
    while(cur != st){
        cur = pre[cur];
        path.push_back(cur);
    }

    cout << path.size() << "\n";
    reverse(path.begin(), path.end());
    for(auto p : path) cout << p << " ";
    cout << "\n";
}