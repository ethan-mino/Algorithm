// Created by SSAFY on 2022-07-26.

#include <bits/stdc++.h>

using namespace std;

int vis[200000];
int pre[200000];

int bfs(int st, int en){
    queue<int> q;
    q.push(st);
    vis[st] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        int nxt[3] = {cur - 1, cur + 1, cur * 2};
        for(int nx : nxt){
            if(nx < 0 || nx > 100000) continue;
            if(vis[nx] != 0) continue;
            q.push(nx);
            vis[nx] = vis[cur] + 1;
            pre[nx] = cur;
        }
    }
    return vis[en] - 1;
}

int main(){
    int n, k; cin >> n >> k;

    cout << bfs(n, k) << "\n";

    int cur = k;
    vector<int> path;
    while(cur != n){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(n);
    reverse(path.begin(), path.end());
    for(auto p : path) cout << p << " ";
}
