#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int vis[MAX];

int bfs(vector<vector<int>> linked, int st){    // st 정점에서 출발했을 때, 방문 가능한 정점의 개수를 반환하는 함수 
    fill(vis, vis + MAX, 0);
    queue<int> q;
    vis[st] = 1;
    q.push(st);

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : linked[cur]){
            if(vis[nxt] != 0) continue;
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

    int n, m; cin >> n >> m;
    
    vector<vector<int>> in(n + 1);  // (u, v)를 연결하는 엣지는 무게가 u > v임을 나타내는 그래프
    vector<vector<int>> out(n + 1); // (u, v)를 연결하는 엣지는 무게가 u < v임을 나타내는 그래프

    while(m--){
        int u, v; cin >> u >> v;
        in[u].push_back(v);
        out[v].push_back(u);
    }

    int ans = 0;
    
    for(int st = 1; st <= n; st++){ // 각 구슬에 대해 무거운 구슬과 가벼운 구슬의 개수를 구함
        int big = bfs(out, st); // 무거운 구슬의 개수
        int small = bfs(in, st);    // 가벼운 구슬의 개수

        // 무거운 구슬 또는 가벼운 구슬의 개수가 (n - 1)/2보다 많다면 무게가 중앙값인 구슬이 될 수 없음
        if(big > ((n - 1)/2) || small > ((n - 1)/2)) ans++; 
    }

    cout << ans << "\n";
}

/*
5 4
1 2
2 3
3 4
4 5
-> 4

4 3
1 2
2 3
3 4
-> 4
*/