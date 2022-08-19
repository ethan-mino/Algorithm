/* BFS 풀이
#include <bits/stdc++.h>
using namespace std;

int vis[1000001];

void bfs(int n){
    queue<int> q;
    q.push(n);
    vis[n] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur < 1) break;
        
        if(cur % 3 == 0 && vis[cur/3] == 0){    // X가 3으로 나누어 떨어지고, 아직 방문하지 않은 경우
            q.push(cur/3);
            vis[cur/3] = vis[cur] + 1;    
        }
        if(cur % 2 == 0 && vis[cur/2] == 0){    // X가 2로 나누어 떨어지고, 아직 방문하지 않은 경우
            q.push(cur/2);
            vis[cur/2] = vis[cur] + 1;
        }
        if(vis[cur - 1] == 0){  // x - 1을 아직 방문하지 않은 경우
            q.push(cur - 1);
            vis[cur - 1] = vis[cur] + 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    bfs(n);
    cout << vis[1] - 1;
}*/

// DP 풀이
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    dp[1] = 0; 
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
    }

    cout << dp[n];
}   
