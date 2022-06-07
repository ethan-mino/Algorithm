#include <bits/stdc++.h>
using namespace std;

#define MAX 301
#define VIRTUAL 0

vector<int> parent(MAX, -1);
int p[MAX][MAX];
int w[MAX];
int n; 

int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_g(int u, int v){
    u = find(u), v = find(v);

    if(u == v) return false;
    if(u > v) parent[u] = v;
    else parent[v] = u;
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<tuple<int, int, int>> edges;

    
    for(int cost, i = 1; i <= n; i++) {
        cin >> cost;    // 우물을 파는 비용 입력 받음
        edges.push_back({cost, VIRTUAL, i});
    }

    for(int i = 1; i <= n; i++){ // 논을 연결하는 비용
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
            edges.push_back({p[i][j], i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int ans = 0, cnt = 0;
    for(int i = 0; i < edges.size(); i++){
        int w, u, v;
        tie(w, u, v) = edges[i];

        if(!is_diff_g(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n) break;
    }

    cout << ans << "\n";
}
/*
3
1
1
1
3 3 3
3 3 3
3 3 3
-> 3

4
1
1
1
11
10 10 10 10
10 10 10 10
10 10 10 2
10 10 2 10
-> 5

3
100
1
100
0 3 1
3 0 10
1 10 0
-> 5


3
100
10000
101
0 20 12
20 0 8
12 8 0
*/