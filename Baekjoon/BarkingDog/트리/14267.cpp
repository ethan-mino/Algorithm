#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
int vis[MAX];
int p[MAX]; // 
int c[MAX]; // c[i]는 i번째 직원이 받은 칭찬

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> linked(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] != -1){
            linked[i].push_back(p[i]);
            linked[p[i]].push_back(i);
        }
    }

    for(int i = 0; i < m; i++){
        int e, d; cin >> e >> d;
        c[e]+= d;
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : linked[cur]){
            if(vis[nxt] != 0) continue;
            q.push(nxt);
            vis[nxt] = 1;
            c[nxt] += c[p[nxt]];
        }
    }
    for(int i = 1; i <= n; i++) cout << c[i] << " ";
}

/*
10 4
-1 1 1 2 2 2 3 7 7 9
3 2
2 5
7 3
9 3
*/