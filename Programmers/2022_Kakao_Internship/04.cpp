// Created by 길민호 on 2022/09/04.

#include <bits/stdc++.h>
using namespace std;

#define GATE 1
#define SUMMIT 2
#define INF 10000010
#define intensity first
#define node second

int ansIntensity = INT_MAX;
int ansSummitNum = INT_MAX;
int maxIntensity[50001];
bool vis[50001];

map<int, int> m;
int N;

void update(int summit, int intensity){
    bool swap = false;

    if(ansIntensity > intensity){
        swap = true;
    }else if(ansIntensity == intensity){
        if(ansSummitNum > summit) swap = true;
    }

    if(swap){
        ansIntensity = intensity;
        ansSummitNum = summit;
    }
}

void dijkstra(int st, vector<vector<pair<int, int>>>& linked){
    priority_queue<pair<int, int>,
            vector<pair<int, int>>, greater<>> pq;

    maxIntensity[st] = 0;
    pq.push({maxIntensity[st], st});
    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();

        if(maxIntensity[cur.node] != cur.intensity) continue;

        for(auto edge : linked[cur.node]){
            int intensity = max(maxIntensity[cur.node], edge.intensity);
            int nxt = edge.node;

            if(maxIntensity[nxt] > intensity){
                maxIntensity[nxt] = intensity;
                pq.push({maxIntensity[nxt], nxt});
                if(m[nxt] == SUMMIT) update(nxt, maxIntensity[nxt]);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    N = n;
    vector<vector<pair<int, int>>> linked(n + 1);

    for(auto gate : gates) m[gate] = GATE;   // 출입구는 1
    for(auto summit : summits) m[summit] = SUMMIT; // 산봉우리는 2, 쉼터는 0

    for(auto path : paths){
        int u = path[0], v = path[1], w = path[2];
        bool from = false, to = false;

        if(m[u] == GATE){   // u가 출입구일 때
            from = true, to = false;
        }else if(m[u] == SUMMIT){   // u가 산봉우리 일 때
            to = true, from = false;
        }else{  // u가 쉼터일 때
            if(m[v] == GATE){
                to = true, from = false;
            }else if(m[v] == SUMMIT){
                from = true, to = false;
            }else{
                from = true, to = true;
            }
        }

        if(from) linked[u].push_back(make_pair(w, v));
        if(to) linked[v].push_back(make_pair(w, u));
    }

    // for(auto gate : gates){
    //     vis[gate] = true;
    //     dfs(gate, 0, linked);
    //     vis[gate] = false;
    // }

    fill(maxIntensity, maxIntensity + N + 1, INT_MAX);

    for(auto gate : gates)
        dijkstra(gate, linked);

    // 산봉우리 번호, 최소 intensity
    return {ansSummitNum, ansIntensity};
}

// int vis[50001];

// dfs solution -> 시간 초과
// void dfs(int cur, int maxIntensity,
//      vector<vector<pair<int, int>>>& linked){
//     // 산봉우리도 지나왔고, 다시 시작점으로 돌아온 경우
//     if(m[cur] == SUMMIT){
//         bool swap = false;

//         if(ans > maxIntensity){
//             swap = true;
//         }else if(ans == maxIntensity){
//             if(cur < ansSummitNum) swap = true;
//         }

//         if(swap){
//             ans = maxIntensity;
//             ansSummitNum = cur;
//         }
//     }else{
//         for(auto edge : linked[cur]){
//             int nx = edge.nxt;
//             int w = edge.weight;

//             // 이미 방문한 경우
//             if(vis[nx]) continue;

//             vis[nx] = true;
//             dfs(nx, max(w, maxIntensity), linked);
//             vis[nx] = false;
//         }
//     }
// }