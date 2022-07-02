// Created by 길민호 on 2022/07/02.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second
#define SIZE 12
int weight[SIZE][SIZE];
int n;
pii st, en;

int d[SIZE][1<<SIZE];  // d[cur][visted]는 현재 cur이고, visted를 방문한 상태일 때, 고객들을 모두 방문하고, 집으로 돌아가는 최소 비용

int TSP(int cur, int visited){
    int &ret = d[cur][visited];
    if(ret != 0) return ret;

    if(visited == (1 << (n + 1))-1) {    // 모두 방문한 경우
        return weight[cur][n + 1];
    }

    ret=100000;
    for(int i = 0; i <= n; i++){
        if(visited&(1<<i)) continue; // 이미 방문한 경우
        // 방문하지 않은 경우
        ret = min(ret, TSP(i, (visited|1<<i)) + weight[cur][i]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int cur = 1;
    while(t--){
        vector<pii> pos;
        fill(&d[0][0], &d[SIZE - 1][1 << SIZE], 0);

        cin >> n;
        cin >> st.x >> st.y;
        cin >> en.x >> en.y;

        pos.push_back(st);
        for(int i = 0; i < n; i++){
            pii c; cin >> c.x >> c.y;
            pos.push_back(c);
        }
        pos.push_back(en);

        for(int i = 0; i < n + 2; i++)
            for(int j = 0; j < n + 2; j++)
                weight[i][j] = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);

        int shortest = TSP(0, 1);
        cout << "#" << cur++ << " " << shortest << "\n";
    }
}
