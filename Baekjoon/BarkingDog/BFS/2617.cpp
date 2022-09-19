// Created by 길민호 on 2022/09/19.

#include <bits/stdc++.h>
using namespace std;

#define HEAVY 0
#define LIGHT 1

#define v first
#define w second

int bfs(int st, int op, vector<vector<pair<int, int>>> & linked){
    int vis[101];
    fill(vis, vis + 101, 0);
    queue<int> q;
    q.push(st);
    vis[st] = 1;

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto nx : linked[cur]){
            if(nx.w != op) continue;
            if(vis[nx.v]) continue;

            q.push(nx.v);
            vis[nx.v] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    // 링크드 리스트
    // 구슬 번호는 1 ~ N
    vector<vector<pair<int, int>>> linked(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // weight가 0인 엣지 a -> b는 a > b임을 나타냄.
        // weight가 1인 엣지 a -> b는 a < b임을 나타냄.
        linked[a].push_back({b, HEAVY});
        linked[b].push_back({a, LIGHT});
    }

    // 각각의 구슬에 대해 무거운 구슬의 개수와 가벼운 구슬의 개수를 구함.
    int cnt = 0; // 무게가 중간이 될 가능성이 전혀 없는 구슬의 개수
    int mid = (n + 1) / 2;

    for (int st = 1; st <= n; st++) {
        // 무거운 구슬의 개수를 구힘
        int heavy = bfs(st, LIGHT, linked);
        // 가벼운 구슬의 개수를 구함
        int light = bfs(st, HEAVY, linked);

        // 무게가 중간인 구슬이 되려면 무게 순서로 (n + 1) / 2번째 구슬이 되어야 함
        // 본인보다 가벼운 구슬 >= (n + 1) / 2이거나 (6의 경우 3개 이상인 경우)
        // 보인보다 무거운 구슬 > (n + 1) / 2면 무게가 중간이 구슬이 절대 될 수 없음 (6의 경우 3개 초과인 경우)
        // 1 2 3 4 5 6
        if(light >= mid || heavy > n - mid){
            cnt++;
        }
    }

    // 무게가 중간인 구슬이 될 수 없는 구슬의 개수 출력
    cout << cnt << "\n";
}