#include <bits/stdc++.h>
using namespace std;

#define MAX 501
int vis[MAX];   // 방문 표시 배열

bool istree(vector<vector<int>> linked, int st){
    queue<int> q;
    q.push(st);
    vis[st] = 1;

    bool tree = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto nxt : linked[cur]){
            if(vis[nxt] != 0 && vis[nxt] != vis[cur] - 1){   // 인접한 정점이 이미 방문했지만, 부모 노드가 아닌 경우
                tree = false;
            }

            if(vis[nxt] != 0) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
        }
    }
    return tree;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 1;
    while(true){
        int n, m; cin >> n >> m;
        if(!n && !m) break;
        vector<vector<int>> linked (n + 1); // 인접 리스트
        for(int i = 0; i < m; i++){ // 인접 리스트 만듦
            int u, v; cin >> u >> v;
            linked[u].push_back(v);
            linked[v].push_back(u);
        }

        fill(vis, vis + MAX, 0);    // 방문 표시 배열 초기화

        int ans = 0;    // 트리의 개수
        for(int st = 1; st <= n; st++){ // 방문하지 않은 정점부터 시작하여 BFS를 수행
            if(vis[st] == 0){
                if(istree(linked, st)) ans++;   // 부분 그래프가 트리인 경우
            }
        }

        cout << "Case " << c++ << ": ";
        if(ans > 1)
            cout << "A forest of " << ans << " trees.";
        else if(ans == 1)
            cout << "There is one tree.";
        else 
            cout << "No trees.";
        cout << "\n";
    }
}

/*
6 6
1 2
2 3
1 3
4 5
5 6
6 4
0 0
*/