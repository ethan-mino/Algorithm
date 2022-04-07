#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> linked(n + 1);  // 인접 리스트

    for(int i =0; i < n - 1; i++){
        int a, b; cin >> a>> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }

    queue<int> q;
    int vis[100001];
    fill(vis, vis + 100001, 0);
    vis[1] = 1;
    q.push(1);

    while(!q.empty()){  // BFS 수행
        int cur = q.front(); q.pop();
        for(int i = 0; i < linked[cur].size(); i++){    // 인접한 노드 방문
            int adj = linked[cur][i];
            if(vis[adj] != 0) continue; // 이미 방문한 경우, 방문하지 않음
            q.push(adj);
            vis[adj] = cur; // vis에 부모 노드 번호 저장
        }
    }
    
    for(int i = 2; i <= n; i++)
        cout << vis[i] << "\n";
}   
