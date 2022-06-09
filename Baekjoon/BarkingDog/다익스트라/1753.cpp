// Created by 길민호 on 2022/06/10.

#include <bits/stdc++.h>
using namespace std;

#define w first
#define n second
#define SIZE 20010
#define INF 5000000

int dist[SIZE];
bool fix[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, st; cin >> v >> e >> st;
    vector<vector<pair<int, int>>> linked(v + 1);
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        linked[u].push_back({w, v});
    }

    fill(dist, dist + SIZE, INF);
    dist[st] = 0;

    priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

    pq.push({dist[st], st});
    while(!pq.empty()){
        pair<int, int> m = pq.top(); pq.pop();
        if(dist[m.n] != m.w) continue;

        for(auto nxt : linked[m.n]){
            int d = dist[m.n] + nxt.w;
            if(dist[nxt.n] > d){
                dist[nxt.n] = d;
                pq.push({dist[nxt.n], nxt.n});
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(dist[i] == INF) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}