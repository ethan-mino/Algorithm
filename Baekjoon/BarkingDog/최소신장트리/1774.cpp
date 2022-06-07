#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

map<int, pair<int, int>> pos;
vector<int> p(1010, -1);
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

double dist(pair<int, int> pos1, pair<int, int> pos2){    // 좌표간의 거리를 반환
    long long a = pos1.x - pos2.x;
    long long b = pos1.y - pos2.y;

    return sqrt(a * a + b * b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int x, y, i = 1; i <= n; i++){
        cin >> x >> y;
        pos[i] = {x, y};    // 각 우주신의 좌표를 저장
    }

    int cnt = 0;    // 선택한 edge의 개수
    for(int u, v, i = 0; i < m; i++){
        cin >> u >> v;
        if(!is_diff_g(u, v)) continue;  // u와 v가 같은 그룹인 경우 해당 edge를 선택하지 않음
        cnt++;  // edge 개수 증가
    }

    vector<tuple<double, int, int>> edges;
    for(int u = 1; u <= n; u++){    // 모든 우주신 간의 모든 edge를 생성
        for(int v = 1; v <= n; v++){
            if(u != v){
                pair<int, int> u_pos = pos[u];
                pair<int, int> v_pos = pos[v];

                double d = dist(u_pos, v_pos);  // 우주신간의 거리
                edges.push_back({d, u, v}); 
            }
        }
    }

    sort(edges.begin(), edges.end());   // 우주신 간의 거리를 기쥰으로 edge를 정렬

    double ans = 0; // 만들어야할 최소의 통로 길이
    for(int i = 0; i < edges.size(); i++){  // 크루스칼 수행
        double w, u, v;
        tie(w, u, v) = edges[i];
        
        if(!is_diff_g(u, v)) continue;
        ans += w;   // 우주신 간의 거리를 더해줌
        cnt++;  // 선택한 edge 개수 증가
        if(cnt == n - 1) break; // edge의 개수가 n - 1이 되면 모든 우주신이 연결된 것이므로 종료
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";
}

/*
5 1
1 0
3 0
5 0
7 0
11 0
1 2
-> 8.00

5 4
1 0
3 0
5 0
7 0
11 0
1 2
2 3
3 4
4 5
-> 0.00

2 0
1000000 1000000
0 0
-> 1414213.56
*/