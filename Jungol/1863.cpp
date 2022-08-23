// Created by SSAFY on 2022-08-23.

#include <bits/stdc++.h>
using namespace std;

#define u first
#define v second

vector<int> p(1000010, -1);

int find(int x){
    if(p[x] < 0) return x;
    else return p[x] = find(p[x]);
}

void isDiff(int u, int v){
    u = find(u); v = find(v);
    if(u != v){
        if(p[u] < p[v]) p[v] = u;
        else p[u] = v;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
    }
    int cnt = 0;

    for(auto edge : edges){
        isDiff(edge.u, edge.v);
    }

    for(int i = 1; i <= n; i++){
        if(p[i] == -1) cnt++;
    }

    cout << cnt << "\n";
}