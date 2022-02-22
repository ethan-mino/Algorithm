#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int vis[1000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    queue<int> q;
    vis[s - 1] = 1;
    q.push(s - 1);

    int ans = -1;
    int dy[2] = {u, -d};

    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(auto dir : dy){
            int ny = cur + dir;

            if(ny < 0 || ny >= f) continue;
            if(vis[ny] != 0) continue;

            vis[ny] = vis[cur] + 1;
            q.push(ny);
        }

        if(vis[g - 1] != 0){
            ans = vis[g - 1];
            break;
        }
    }

    if(ans == -1) cout << "use the stairs";
    else cout << ans - 1;
}
