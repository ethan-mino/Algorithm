#include <bits/stdc++.h>
using namespace std;

#define G 0

vector<int> p(1010, -1);
int n, m, k; 

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int v, i = 0; i < k; i++){ // 발전소가 설치된 도시의 번호가 주어진다.
        cin >> v; 
        is_diff_g(G, v);  // 해당 도시를 G 그룹에 포함시킨다.
    }

    vector<tuple<int, int, int>> edges; // 간선을 저장하는 vector

    for(int i =0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v}); // 모든 간선을 edges에 추기
    }

    sort(edges.begin(), edges.end());   // 간선을 cost를 기준으로 정렬

    int ans = 0; // 모든 도시를 발전소에 연결시키기 위한 최소 비용
    int cnt = k;   // 그룹 G에 포함된 도시의 개수
    for(int i = 0; i < edges.size(); i++){  // 크루스칼 수행
        int w, u, v;
        tie(w, u, v) = edges[i];    
        if(!is_diff_g(u, v)) continue;  // u와 v가 같은 그룹인 경우 해당 간선을 선택하지 않음
        // u와 v가 서로 다른 간선인 경우, 해당 간선을 선택
        ans += w;   // 해당 간선의 비용을 더해줌
        cnt++;  // 그룹 G에 포함된 도시의 개수 증가
        if(cnt == n) break; // 모든 도시가 그룹 G에 포함된 경우 종료
    }
    cout << ans << "\n";
}