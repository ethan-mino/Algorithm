#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
int c[MAX][MAX];
vector<int> p(MAX, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
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

    int n; cin >> n;
    vector<tuple<int, int, int>> edges;
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            if(i != j) edges.push_back({c[i][j], i, j});
        }
    }

    sort(edges.begin(), edges.end());

    long long ans = 0, cnt = 0;
    for(int i =0; i < edges.size(); i++){
        int w, u, v;
        tie(w, u, v) = edges[i];

        if(!is_diff_g(u, v)) continue;
        ans += w;
        cnt++;
    }
    cout << ans << "\n";
}