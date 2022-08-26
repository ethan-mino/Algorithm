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

    set<int> zero;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) zero.insert(i);

    vector<int> result;
    
    while(!zero.empty()){
        int cur = *zero.begin(); zero.erase(zero.begin());
        result.push_back(cur);

        for(auto nxt : linked[cur]){
            in[nxt]--;
            if(in[nxt] == 0) zero.insert(nxt);
        }
    }

    for(auto r : result) cout << r << " ";
}

/*
4 3
4 2
2 1
1 3
-> 4 2 1 3
*/