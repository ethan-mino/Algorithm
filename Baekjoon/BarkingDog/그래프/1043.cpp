#include <bits/stdc++.h>
using namespace std;

int vis[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;    // 사람 수와 파티의 수 입력 받음
    int tn; cin >> tn; 

    vector<vector<int>> party(m);   // 각 파티에 참석하는 사람
    vector<vector<int>> linked(n + 1); 
    vector<int> t(tn); // 진실을 아는 사람들
    
    for(int i = 0; i < tn; i++) cin >> t[i];   // 진실을 아는 사람들 입력 받음

    for(int i = 0; i < m; i++){
        int c; cin >> c; 
        vector<int> participant(c);

        for(int j = 0; j < c; j++) cin >> participant[j];
        party[i] = participant;
        for(int j = 0; j < c - 1; j++){
            int u = participant[j], v = participant[j + 1]; 
            linked[u].push_back(v);
            linked[v].push_back(u);
        }
    }

    for(int i = 0; i < t.size(); i++){
        int st = t[i];
        queue<int> q;
        q.push(st);
        vis[st] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : linked[cur]){
                if(vis[nxt] != 0) continue;
                q.push(nxt);
                vis[nxt] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        bool avail = true;
        for(int j = 0; j < party[i].size(); j++){
            if(vis[party[i][j]] != 0) avail = false;
        }
        if(avail) ans++;
    }

    cout << ans << "\n";
}

// 과장된 이야기를 할 수 있는 파티의 개수
// 과장된 이야기를 하려면 해당 파티에 오는 사람들은 모두 진실을 알지 못해야함.
// 진실을 아는 사람이 없다면, 모든 파티에서 과장을 할 수 있음
// 진실을 아는 사람이 있다면, 진실을 아는 사람과 같이 파티에 참석한 사람이 참석한 파티에서도 거짓말을 할 수 없음
// 파티 개수의 최댓값

/*
4 3
0
4 1 2 3 4
2 1 2
2 3 4
-> 2

그리디?
현재 과장이 가능한 파티중 인원이 가장 적은 파티부터?
단순히 인원이 적은 파티부터하면 파티 개수가 더 적어지는 경우는?
8 3
0
2 1 5
2 1 2 3 4
2 5 6 7 8
-> 2


*/