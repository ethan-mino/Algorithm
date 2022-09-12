// Created by 길민호 on 2022/09/12.
#include <bits/stdc++.h>

using namespace std;

#define INF 50000000
// S -> A + S -> B
// S -> T + T -> A + T -> B
int dist[200][200];


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    s--; a--; b--;

    fill(&dist[0][0], &dist[199][200], INF);
    for(int u = 0; u < n; u++) dist[u][u] = 0;

    for(auto edge : fares){
        int a = edge[0] - 1, b = edge[1] - 1, w = edge[2];
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for(int pass = 0; pass < n; pass++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(dist[u][v] > dist[u][pass] + dist[pass][v]){
                    dist[u][v] = dist[u][pass] + dist[pass][v];
                }
            }
        }
    }

    int ans = dist[s][a] + dist[s][b];
    for(int pass = 0; pass < n; pass++){
        ans = min(ans, dist[s][pass] + dist[pass][a] + dist[pass][b]);
    }

    return ans;
}