// Created by 길민호 on 2022/08/08.

#include <bits/stdc++.h>
using namespace std;

#define w first
#define v second
#define dist first
#define INF 100000000

int n;
int distance(int st, vector<vector<pair<int, int>>> linked){
    int d[10010];
    fill(d, d + n, INF);

    priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<>> q;

    d[st] = 0;
    q.push({d[st], st});
    while(!q.empty()){
        pair<int, int> cur = q.top(); q.pop();
        if(d[cur.v] != cur.dist) continue;
        for(auto nxt : linked[cur.v]){
            if(d[nxt.v] > d[cur.v] + nxt.w){
                d[nxt.v] = d[cur.v] + nxt.w;
                q.push({d[nxt.v], nxt.v});
            }
        }
    }

    return *max_element(d + 1, d + n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<pair<int, int>>> linked( n + 1);

    for(int i =0 ; i < n - 1; i++){
        int p, c, w; cin >> p >> c >> w;
        linked[p].push_back({w, c});
        linked[c].push_back({w, p});
    }

    vector<int> leaf;
    for(int v = 2; v <= n; v++){
        if(linked[v].size() == 1) leaf.push_back(v);
    }

    int ans = INT_MIN;
    for(int st = 0; st < leaf.size(); st++){
        ans = max(ans, distance(leaf[st], linked));
    }

    cout << ans << "\n";
}