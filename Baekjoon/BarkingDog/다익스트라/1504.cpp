// Created by 길민호 on 2022/06/21.

#include <bits/stdc++.h>
using namespace std;

#define INF 200000000
#define SIZE 810
#define w first
#define v second

int dist[SIZE];
int n, e;
vector<vector<pair<int, int>>> linked(SIZE);

int shortest(int st, int en){
    fill(dist, dist + n + 1, INF);

    priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(dist[cur.v] != cur.w) continue;

        for(auto nxt : linked[cur.v]){
            if(dist[nxt.v] > dist[cur.v] + nxt.w){
                dist[nxt.v] = dist[cur.v] + nxt.w;
                pq.push({dist[nxt.v], nxt.v});
            }
        }
    }

    return dist[en];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        linked[a].push_back({c, b});
        linked[b].push_back({c, a});
    }

    int v1, v2; cin >> v1 >> v2;

    int path1 = shortest(1, v1) + shortest(v1, v2) + shortest(v2, n);
    int path2 = shortest(1, v2) + shortest(v2, v1) + shortest(v1, n);
    if(path1 >= INF && path2 >= INF) cout << -1;
    else cout << min({path1, path2});
}

// 세준이는 한 번 이동했던 정점은 물론, 한 번 이동했던 간선도 다시 이동할 수 있다.
// 임의로 주어진 두 정점은 반드시 통과해야한다.
// 그러한 경로가 없을 때에는 -1을 출력한다.


// 1 -> x -> a -> x -> b -> x -> n
// 1 -> x -> b -> x -> a -> x -> n