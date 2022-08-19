// Created by 길민호 on 2022/07/02.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 101
#define CASE 10
#define VIS_INIT -1

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cur = 1;
    while(cur <= CASE){
        int l, st; cin >> l >> st;
        vector<vector<int>> linked(SIZE);
        for(int i = 0; i < l; i += 2){
            int from, to; cin >> from >> to;
            linked[from].push_back(to);
        }

        int vis[SIZE];
        fill(vis, vis + SIZE, VIS_INIT);
        queue<int> q;
        q.push(st);
        vis[st] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : linked[cur]){
                if(vis[nxt] != VIS_INIT) continue;
                vis[nxt] = vis[cur] + 1;
                q.push(nxt);
            }
        }

        int m = *max_element(vis, vis + SIZE);
        int idx = 0;
        for(int i = 0; i < SIZE; i++) if(vis[i] == m) idx = i;
        cout << "#" << cur++ << " " << idx << "\n";
    }
}
