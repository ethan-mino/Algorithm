#include <bits/stdc++.h>
using namespace std;

int vis[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);  // 인접 리스트

    for(int i = 0; i < m; i++){ // 인접 리스트 만들어줌
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    int n_graph = 0;    // 그래프의 개수
    int n_cycle = 0;    // 싸이클의 개수

    for(int st = 1; st <= n; st++){
        if(vis[st] == 0){   // 아직 방문하지 않은 경우 BFS 수행
            n_graph++;  // 그래프의 개수 증가
            queue<int> q;
            q.push(st);
            vis[st] = 1;
            
            set<int> vertice;   // 해당 그래프에 연결된 정점
            vertice.insert(st);
            
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt : linked[cur]){
                    if(vis[nxt] != 0) continue; // 이미 방문한 경우 방문하지 않음
                    q.push(nxt);    
                    vertice.insert(nxt);    // 방문한 정점을 저장
                    vis[nxt] = 1;
                }
            }
            int edges = 0;  // 해당 그래프의 간선 개수
            for(auto v : vertice) edges += linked[v].size();    // 방문한 정점의 간선 개수를 더해줌
            n_cycle += (edges / 2) - (vertice.size() - 1);  // 싸이클의 개수
        }
    }
    cout << n_cycle + n_graph - 1 << "\n";  // 싸이클의 개수 + 그래프의 개수 - 1
}
/*
3 2
1 2 
2 3
-> 0

8 7
1 3
1 2
2 4
3 4
5 6
5 7
6 7
-> 4

5 6
1 2 
1 3
1 4
2 5
3 5
4 5
-> 2
*/