// Created by 길민호 on 2022/09/04.
#include <bits/stdc++.h>
using namespace std;
// Created by 길민호 on 2022/08/18.
#define dist first
#define w first
#define node second
#define algo first
#define code second
#define INF 1000

pair<int, int> pre[190][190];
int dist[152][152];   // * dist[a][c]는 {초기 알고력, 초기 코딩력}으로부터 {알고력 a, 알고력 c}까지의 최단 거리
vector<pair<int, pair<int, int>>> linked[152][152]; // * {알고력, 코딩력} : [{weight, {알고력, 코딩력}}]

// * 다익스트라를 이용한 코드
// * 초기 알고력, 코딩력으로부터 모든 문제를 풀 수 있는 알고력과 코딩력까지의 최단 거리를 구함
// ! 단, 알고력, 코딩력이 모두 초기 알고력, 코딩력보다 낮거나 같은 경우 거리를 0으로 초기화
int solution(int alp, int cop, vector<vector<int>> problems){
    // * 엣지 생성
    // {알고력, 코딩력}
    for(int a = alp; a <= 150; a++){
        for(int c = cop; c <= 150; c++){
            // * 알고리즘 공부, 코딩 공부를 통한 역량 상승 엣지
            // ! 단, weight는 1
            linked[a][c].push_back({1, {a + 1, c}});
            linked[a][c].push_back({1, {a, c + 1}});

            // * 문제 풀이를 통한 역량 상승 엣지
            for(auto p : problems){
                // ! 노드의 알고력, 코딩력이 모두 문제의 알고력, 코딩력보다 높거나 같은 경우에만 엣지 생성
                // * weight는 문제를 푸는데 드는 시간
                if(a >= p[0] && c >= p[1]){
                    // if(c + p[3] > 180 || a + p[2] > 180) continue;
                    linked[a][c].push_back({p[4], {a + p[2], c + p[3]}});
                }
            }
        }
    }

    int alpM = alp;
    int copM = cop;

    // * 문제들 중 최대 알고력, 최대 코딩력을 찾음
    for(auto p : problems){
        alpM = max(alpM, p[0]);
        copM = max(copM, p[1]);
    }

    // ! 우선순위 큐 사용
    priority_queue<pair<int, pair<int, int>>, vector
            <pair<int, pair<int, int>>>,
            greater<>> q;

    fill(&dist[0][0], &dist[151][152], INF);

    // ! 단, 알고력, 코딩력이 모두 초기 알고력, 코딩력보다 낮은 경우 거리를 0으로 초기화
    for(int a = 0; a <= alp; a++)
        for(int c = 0; c <= cop; c++)
            if(a <= alp && c <= cop) dist[a][c] = 0;

    // * 다익스트라 코드
    q.push({dist[alp][cop], {alp, cop}});

    while(!q.empty()){
        // * 시작점으로부터의 거리가 가장 짧은 것을 pop()
        pair<int, pair<int, int>> cur = q.top(); q.pop();

        // ! dist 배열에 저장된 거리와 다르다면 continue
        if(dist[cur.node.algo][cur.node.code] != cur.dist) continue;

        for(auto nx : linked[cur.node.algo][cur.node.code]){
            // * 거리가 더 짧은 경우, 거리 갱신
            int nxAlgo = min(150, nx.node.algo);
            int nxCode = min(150, nx.node.code);

            if(dist[nxAlgo][nxCode] > dist[cur.node.algo][cur.node.code] + nx.w){
                cout <<  cur.node.algo << " " << cur.node.code << " " << nxAlgo << " " << nxCode << "\n";
                dist[nxAlgo][nxCode] = dist[cur.node.algo][cur.node.code] + nx.w;
                q.push({dist[nxAlgo][nxCode], {nxAlgo, nxCode}});
                // pre[nx.node.algo][nx.node.code] = cur.node;
            }
        }
    }

    int ans = dist[alpM][copM];
    for(int i = alpM; i <= 150; i++)
        for(int j = copM; j <= 150; j++)
            ans = min(ans, dist[i][j]);

    return ans;
}


int main(){
    solution(150, 110, {{0, 0, 30, 10, 2}, {150, 150, 3, 2, 1}});
}