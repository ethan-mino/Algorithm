// Created by SSAFY on 2022-08-02.

#include <bits/stdc++.h>
using namespace std;

vector<int> linked[1001];

void bfs(int st){
    int vis[1010];
    fill(vis, vis + 1010, 0);

    queue<int> q;
    q.push(st);
    vis[st] = 1;
    cout << st << " ";
    while(!q.empty()){
        int cur = q.front(); q.pop();

       for(int nx : linked[cur]){
           if(!vis[nx]){
               cout << nx << " ";
               q.push(nx);
               vis[nx] = 1;
           }
       }
    }
}

void dfs(int st){
    int vis[1010];
    fill(vis, vis + 1010, 0);

    stack<int> s;
    s.push(st);

    while(!s.empty()){
        int cur = s.top(); s.pop();

        if(!vis[cur]){
            cout << cur << " ";
            vis[cur] = 1;
        }

        for(int nx : linked[cur]){
            if(!vis[nx]) s.push(nx);
        }
    }
}

int main(){
    int n, m, st; cin >> n >> m >> st;

    for(int i = 0; i < m; i++){
        int s, e; cin >> s >> e;
        linked[s].push_back(e);
        linked[e].push_back(s);
    }

    for(int i = 1; i <= n; i++)
        sort(linked[i].begin(), linked[i].end(), greater<>());

    dfs(st);
    cout << "\n";

    for(int i = 1; i <= n; i++)
        sort(linked[i].begin(), linked[i].end());
    bfs(st);
}
