#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

tuple<int, int, int> edges[100010];
vector<int> p(MAX, -1);

int find(int v){
    if(p[v] < 0) return v;
    return p[v] = find(p[v]);
}

bool is_diff_g(int u, int v){
    u = find(u), v = find(v);

    if(u == v) return false;
    if(u > v) p[u] = v;
    else p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e; cin >> v >> e;

    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    sort(edges, edges +e);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < e; i++){
        int w, a, b;
        tie(w, a, b) = edges[i];

        if(!is_diff_g(a, b)) continue;
        ans += w;
        cnt++;
        if(cnt == v - 1) break;
    }
    cout << ans << "\n";
}