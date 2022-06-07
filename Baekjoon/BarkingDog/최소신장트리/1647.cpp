#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010
vector<tuple<int, int, int>> edges;
vector<int> p(100010, -1);

int find(int x){    // x의 root를 찾는 함수
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

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w; 
        cin >> a >> b >> w;
        edges.push_back({w, a, b}); // 각 길에 대한 정보를 입력 받음
    }


    sort(edges.begin(), edges.end());   // 길의 유지 비용 기준으로 간선을 정렬

    long long ans = 0, cnt = 0;
    int min_w = INT_MIN;
    for(int i = 0; i < edges.size(); i++){  // 크루스칼 알고리즘 수행
        int w, u, v;
        tie(w, u, v) = edges[i];    // 현재 edge의 정보

        if(!is_diff_g(u, v)) continue;  // u와 v가 같은 그룹이면 continue, 다른 그룹이면 해당 간선을 선택
        ans += w;   // 해당 길의 유지비를 더해줌
        min_w = max(min_w, w);  // 가장 큰 유지비를 저장
        if(cnt == v - 1) break; // 모든 집이 연결되었다면 break
    }
    cout << ans - min_w << "\n";    // 모든 집을 연결하는 최소 비용에서 비용이 가장 높은 길을 제거
}