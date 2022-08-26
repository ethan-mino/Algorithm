// Created by SSAFY on 2022-08-26.

#include <bits/stdc++.h>
using namespace std;

int degree[1001];
int dist[1001];

int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m; cin >> n >> m;
    // 선수 과목이 없는 것을 방문
    vector<int> linked[n + 1];

    for(int i =0 ; i < m; i++){
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        degree[v]++;
    }

    int cnt = 0;
    int term = 1;

    queue<int> q;
    for(int v = 1; v <= n; v++)
        if(degree[v] == 0) {
            q.push(v);
            dist[v] = term;
        }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nx : linked[cur]){
            degree[nx]--;
            if(degree[nx] == 0) {
                q.push(nx);
                dist[nx] = dist[cur] + 1;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}