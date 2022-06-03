#include <bits/stdc++.h>
using namespace std;

int p[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    p[1] = -1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(auto nxt : linked[cur]){
            if(nxt == p[cur]) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }

    for(int i = 2; i <= n; i++)cout << p[i] << "\n";
}