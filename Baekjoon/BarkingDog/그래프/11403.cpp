#include <bits/stdc++.h>
using namespace std;

#define idx first
#define s second

int vis[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> linked(n + 1);

    while(true){
        int u, v;
        cin >> u >> v;
        if(u == -1 || v == -1) break;

        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    vector<int> score(n + 1);
    for(int i = 1; i <= n; i++){
        fill(vis, vis + n + 1, 0);

        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : linked[cur]){
                if(vis[nxt] != 0) continue;
                q.push(nxt);
                vis[nxt] = vis[cur] + 1;
            }
        }

        for(int j = 1; j <= n; j++)
            score[i] = max(score[i], vis[j]);
        score[i]--;
    }

    int m = *min_element(next(score.begin()), score.end());

    vector<pair<int, int> > c;
    for(int i = 1; i <= n; i++)
        if(score[i] == m) c.push_back({i, score[i]});
    
    cout << c[0].s << " " << c.size() << "\n";
    for(int i = 0; i < c.size(); i++)
        cout << c[i].idx << " ";
}