#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
#define UP_HILL_WEIGHT 100

vector<int> p(MAX, -1) ;
int n, m; 

int find(int x){    // x의 그룹의 Root를 반환
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_g(int u, int v){   // u와 v가 같은 그룹이면 false를 반환, 다른 그룹이면 union을 수행한 뒤 true를 반환
    u = find(u), v = find(v);
    if(u == v) return false;
    if(u == v) p[u] = v;
    else p[v] = u;
    return true;
}

int MST(vector<tuple<int, int, int>> edges){    // MST 수행
    fill(p.begin(), p.end(), -1);   // 각 정점이 속한 그룹의 root 초기화

    int up = 0, cnt = 0;    // up은 오르막길의 개수, cnt는 선택한 간선의 개수
    for(int i = 0; i < edges.size(); i++){
        int w, u, v;
        tie(w, u, v) = edges[i];    // 현재 확인하려는 간선

        if(!is_diff_g(u, v)) continue;  // u와 v가 같은 그룹이라면 continue
        if(w == UP_HILL_WEIGHT) up++;   // 오르막길의 개수 증가
        cnt++;  // 간선의 개수 증가
        if(cnt == n) break; // 입구를 포함하기 때문에, 간선의 개수가 n개가 되어야함
    }
    return up * up;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    for(int i =0; i < m + 1; i++){
        int u, v, c; cin >> u >> v >> c;
        int w = (c == 0) ? UP_HILL_WEIGHT : 1;  // 내리막길보다 오르막길의 비용을 높게 설정
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());   // 내리막길을 먼저 선택하도록 간선을 정렬
    int min_c = MST(edges);

    sort(edges.begin(), edges.end(), greater<>());  // 오르막길을 먼저 선택하도록 간선을 정렬
    int max_c = MST(edges);

    cout << max_c - min_c << "\n";  // 최악의 피로도 - 최선의 피로도
}