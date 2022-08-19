#include <bits/stdc++.h>
using namespace std;

#define u first
#define v second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);  // 인접 리스트

    for(int i = 0; i < m; i++){
        pair<int, int> p; cin >> p.u >> p.v;
        linked[p.u].push_back(p.v); // 방향 없는 그래프이기 때문에 두 정점에 대해서 간선을 저장
        linked[p.v].push_back(p.u);
    }

    int ans = 0;
    int vis[1001];  // 방문 표시 배열
    fill(vis, vis + 1001, 0);
    for(int i = 1; i <= n; i++){ // 각각의 정점에 대해 BFS 수행
        if(vis[i] != 0) continue;   // 아직 방문하지 않은 정점에 대해서 BFS 수행
        queue<int> q;

        q.push(i);
        vis[i] = 1;
        int cnt = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j = 0; j < linked[cur].size(); j++){
                if(vis[linked[cur][j]] != 0) continue;   // 이미 방문한 경우, 방문하지 않음
                q.push(linked[cur][j]);
                vis[linked[cur][j]] = 1;
                cnt++;
            }
        }
        ans += 1;   // 연결 요소 증가
    }
    cout << ans;
}   