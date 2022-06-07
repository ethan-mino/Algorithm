#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010
vector<tuple<int, int, int>> edges;
vector<int> p(100010, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_g(int u, int v){
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
    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, w; 
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
        linked[a].push_back(b);
        linked[b].push_back(a);
    }


    sort(edges.begin(), edges.end());

    long long ans = 0, cnt = 0;
    int min_w = INT_MIN;
    for(int i = 0; i < edges.size(); i++){
        int w, u, v;
        tie(w, u, v) = edges[i];

        if(!is_diff_g(u, v)) continue;
        ans += w;
        min_w = max(min_w, w);
        if(cnt == v - 1) break;
    }
    cout << ans - min_w << "\n";
}