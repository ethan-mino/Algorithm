// Created by 길민호 on 2022/09/05.

#include <bits/stdc++.h>
using namespace std;

int dp[10010];

int bfs(int st, vector<vector<int>>& linked){
    int vis[10010];
    fill(vis, vis + 10010, 0);
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    int cnt = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto nxt : linked[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> s;
    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        linked[v].push_back(u);
    }

    int maxCnt = INT_MIN;
    vector<int> cntMaxNode;
    for(int v = 1; v <= n; v++){
        int cnt = bfs(v, linked);
        if(cnt == maxCnt){
            cntMaxNode.push_back(v);
        }else if(cnt > maxCnt){
            maxCnt = cnt;
            cntMaxNode = {};
            cntMaxNode.push_back(v);
        }
    }

    sort(cntMaxNode.begin(), cntMaxNode.end());
    for(auto v : cntMaxNode) cout << v << " ";
}
