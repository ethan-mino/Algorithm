// Created by 길민호 on 2022/06/21.
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
#define SIZE 1010
#define w first
#define v second

int n, m, x;
vector<vector<pair<int, int>>> linked(SIZE);

vector<int> shortest(int st){
    priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

    vector<int> dist(n + 1);
    fill(dist.begin(), dist.end(), INF);
    dist[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.v] != cur.w) continue;

        for(auto nxt : linked[cur.v]){
            if(dist[nxt.v] > dist[cur.v] + nxt.w){
                dist[nxt.v] = dist[cur.v] + nxt.w;
                pq.push({dist[nxt.v], nxt.v});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        linked[u].push_back({w, v});
    }

    vector<int> to_x(n + 1);
    for(int st = 1; st <= n; st++){
        vector<int> d = shortest(st);
        to_x[st] = d[x];    // dist[st]는 st->x까지의 최단 거리
    }

    vector<int> dist(n + 1);
    vector<int> from_x = shortest(x);
    for(int i = 1; i <= n; i++) dist[i] = to_x[i] + from_x[i];

    cout << *max_element(dist.begin(), dist.end()) << "\n";
}