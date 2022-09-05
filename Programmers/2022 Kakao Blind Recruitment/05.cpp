// Created by 길민호 on 2022/09/05.

#include <bits/stdc++.h>

using namespace std;

int ans = 1;    // 모을 수 있는 양의 최대 수
bool visited[17];

// remainSheep은 남은 양의 수
// sheepCnt는 모인 양의 개수, wolfCnt는 모인 늑대의 수
// visitAvail은 아직 방문하지 않았지만, 방문 가능한 노드 번호 벡터
void back(int remainSheep, int sheepCnt, int wolfCnt,
          vector<int>& visitAvail, vector<int> & infos, vector<vector<int>>& linked){
    ans = max(sheepCnt, ans);

    // 아직 방문하지 않았지만, 방문 가능한 노드가 있고, 양이 남아 있는 경우
    // 남은 양의 수 + 현재 모은 양의 수가 최대 양의 개수보다 큰 경우에만 이동
    if(remainSheep != 0 && remainSheep + sheepCnt > ans){
        for(auto nx : visitAvail){    // 현재 방문 가능한 노드를 방문
            int tmpSheepCnt = sheepCnt;
            int tmpWolfCnt = wolfCnt;
            int tmpRemainSheepCnt = remainSheep;
            vector<int> tmpVisitAvail;

            if(infos[nx] == 0){ // 방문하는 곳에 양이 있는 경우
                tmpSheepCnt++;  // 양의 수 증가
                tmpRemainSheepCnt--;    // 남아있는 양의 수 감소
            }else{  // 방문하는 곳에 늑대가 있는 경우
                tmpWolfCnt++;
                // 늑대에게 양이 잡아먹히는 경우 백트래킹 진행 X
                if(tmpWolfCnt >= tmpSheepCnt){
                    continue;
                }
            }

            for(auto nxtnx : linked[nx]){
                if(!visited[nxtnx]) tmpVisitAvail.push_back(nxtnx);
            }

            for(auto avail : visitAvail){
                if(avail != nx) tmpVisitAvail.push_back(avail);
            }

            visited[nx] = true;
            back(tmpRemainSheepCnt, tmpSheepCnt, tmpWolfCnt, tmpVisitAvail, infos, linked);
            visited[nx] = false;
        }
    }
}

int solution(vector<int> infos, vector<vector<int>> edges) {
    vector<vector<int>> linked(infos.size());
    int sheepCnt = 0;

    for(auto info : infos){
        if(info == 0) sheepCnt++;
    }

    for(auto edge : edges){
        int u = edge[0], v = edge[1];
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    vector<int> visitAvail;
    visited[0] = true;
    for(int nx : linked[0]){
        visitAvail.push_back(nx);
    }

    back(sheepCnt - 1, 1, 0, visitAvail, infos, linked);

    return ans;
}