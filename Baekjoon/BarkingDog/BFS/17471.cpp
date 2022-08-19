// Created by SSAFY on 2022-08-02.

#include <bits/stdc++.h>
using namespace std;

int pop[20];
vector<int> linked[20];
int part[20];
int n;

pair<int, int> population(){
    int vis[20], pp[2];
    fill(vis , vis + 20, 0);
    fill(pp, pp + 2, 0);

    int area = 0;
    for(int st = 1; st <= n; st++){
        if(!vis[st]){
            queue<int> q;

            q.push(st);
            vis[st] = 1;
            pp[area] += pop[st];

            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nx : linked[cur]){
                    if(!vis[nx] && part[nx] == part[st]){
                        q.push(nx);
                        vis[nx] = 1;
                        pp[area] += pop[nx];
                    }
                }
            }
            area++;
        }
    }

    return {area, abs(pp[0] - pp[1])};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> pop[i];

    for(int i = 1; i <= n; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int t; cin >> t;
            linked[i].push_back(t);
            linked[t].push_back(i);
        }
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        vector<int> np;
        for(int j = 0; j < n - i; j++) np.push_back(0);
        for(int j = 0; j < i; j++) np.push_back(1);

        do{
            for(int j = 1; j <= np.size(); j++){
                part[j] = np[j - 1];
            }
            pair<int, int> r = population();
            if(r.first == 2) ans = min(ans, r.second);
        }while(next_permutation(np.begin(), np.end()));
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}



// 구역 = 하나의 노드
//
