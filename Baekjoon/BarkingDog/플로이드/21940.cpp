#include <bits/stdc++.h>
using namespace std;

#define INF 2000000
#define SIZE 201
int dist[SIZE][SIZE];
int city[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m;

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++){
        int u, v, t; cin >> u >> v >> t;
        dist[u][v] = min(dist[u][v], t);
    }
    cin >> k;
    for(int i = 1; i <= k; i++) cin >> city[i];

    for(int pass = 1; pass <= n; pass++){
        for(int st = 1; st <= n; st++){
            for(int en = 1; en <= n; en++){
                int d = dist[st][pass] + dist[pass][en];
                if(dist[st][en] > d) dist[st][en] = d;
            }
        }
    }
    
    int ans = INT_MAX;
    vector<int> cities;
    for(int c = 1; c <= n; c++){
        int time = INT_MIN;
        for(int i = 1; i <= k; i++){
            time = max(time, dist[city[i]][c] + dist[c][city[i]]);
        }
        if(ans > time) {
            cities.clear();
            cities.push_back(c);
            ans = time; 
        }else if(ans == time){
            cities.push_back(c);
        }
    }

    for(auto c : cities) cout << c << " ";
}


// 준형이와 친구들이 도로를 이용하여 갈 수 있는 도시만 선택한다.
// 준형이와 친구들의 왕복시간 들 중 최대가 최소가 되는 도시 X를 선택한다.
// 만약 가능한 도시 X가 여러 개인 경우는 도시의 번호를 오름차순으로 출력한다.
