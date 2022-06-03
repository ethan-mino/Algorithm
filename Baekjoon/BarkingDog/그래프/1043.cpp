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
        vector<int> participant(c); // i번째 파티에 참석하는 사람들

        for(int j = 0; j < c; j++) cin >> participant[j];   // i번째 파티에 참석하는 사람들 입력 받음
        party[i] = participant;
        
        for(int j = 0; j < c - 1; j++){ // 같은 파티에 참석한 사람들을 연결
            int u = participant[j], v = participant[j + 1]; 
            linked[u].push_back(v);
            linked[v].push_back(u);
        }
    }

    for(int i = 0; i < t.size(); i++){  // 진실을 아는 사람을 시작점으로 하여 BFS 수행
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
        for(int j = 0; j < party[i].size(); j++){   // 파티에 참석한 인원들이 모두 진실을 아는 사람들과 관련이 없는 경우에만 거짓말을 할 수 있음
            if(vis[party[i][j]] != 0) avail = false;
        }
        if(avail) ans++;
    }

    cout << ans << "\n";
}