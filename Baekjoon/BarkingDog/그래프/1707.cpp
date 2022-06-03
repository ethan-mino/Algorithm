#include <bits/stdc++.h>
using namespace std;

#define MAX 20010
#define COLOR_1 1
#define COLOR_2 2

int vis[MAX];

bool isb(vector<vector<int>> linked, int v){   // 해당 그래프가 이분 그래프인지 확인하는 함수
    fill(vis, vis + MAX, 0);    // 방문 배열 초기화

    for(int st = 1; st <= v; st++){ // 방문하지 않은 정점에 대해 BFS 수행
        if(vis[st] == 0){   // 방문하지 않은 정점이라면
            queue<int> q;
            q.push(st);
            vis[st] = COLOR_1;    // 시작 정점에 1번 색상 부여

            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt : linked[cur]){    // 각 인접한 정점에 대해 수행
                    if(vis[nxt] != 0) { // 인접한 정점을 이미 방문한 경우
                        if(vis[nxt] == vis[cur]) return false;  // 같은 색이라면 false를 반환
                        else continue;
                    }

                    q.push(nxt);
                    // 인접한 정점을 서로 다른 색상으로 색칠함
                    if(vis[cur] == COLOR_1) vis[nxt] = COLOR_2; 
                    else vis[nxt] = COLOR_1;
                }
            }
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    while(k--){
        int v, e; cin >> v >> e;
        int cnt = 0;
        vector<vector<int>> linked(v + 1); // 인접 리스트

        for(int i = 0; i < e; i++){ // 인접 리스트 만듦
            int u, v; cin >> u >> v;
            linked[u].push_back(v);
            linked[v].push_back(u);
        }

        bool b = isb(linked, v);    // 해당 그래프가 이분 그래프인지 확인

        if(b) cout << "YES";    // 이분 그래프인 경우
        else cout << "NO";
        cout << "\n";
    }
}