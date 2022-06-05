#include <bits/stdc++.h>
using namespace std;

#define MAX 32010

int in[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        in[v]++;
    }

    queue<int> zero;
    vector<int> result;

    for(int v = 1; v <= n; v++)
        if(in[v] == 0) zero.push(v);

    while(!zero.empty()){
        int cur = zero.front(); zero.pop();
        result.push_back(cur);

        for(auto nxt : linked[cur]){
            in[nxt]--;
            if(in[nxt] == 0) zero.push(nxt);
        }
    }

    for(auto r : result) cout << r << " ";
}