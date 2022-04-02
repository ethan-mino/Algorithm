#include <bits/stdc++.h>
using namespace std;

bool vis[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);  // 인접 리스트를 이용
    for(int i = 0; i < m; i++){ // 인접한 쌍을 입력 받아 인접 리스트에 저장
        int a, b; cin >> a >> b;
        linked[a].push_back(b); 
        linked[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){  //   BFS 수행
        int cur = q.front(); q.pop();
        for(int i = 0; i < linked[cur].size(); i++){
            if(vis[linked[cur][i]]) continue;   // 이미 방문한 경우, 방문하지 않음
            q.push(linked[cur][i]);
            vis[linked[cur][i]] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(vis[i]) cnt++;
    cout << cnt - 1;
}