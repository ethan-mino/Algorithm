#include <bits/stdc++.h>
using namespace std;

int board[101];
int vis[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m + n; i++){
        pair<int, int> t; cin >> t.first >> t.second;
        board[t.first] = t.second;
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 1; i <= 6; i++){
            int nx = cur + i;
            if(nx > 100 || vis[nx] != 0) continue;
            vis[nx] = vis[cur] + 1;
            
            if(board[nx] != 0){ // 사다리 또는 뱀이 있는 칸인 경우
                int j = board[nx];  // 사다리 또는 뱀을 통해 이동하는 번호
                if(vis[j] != 0) continue;   // 이미 방문한 경우, 방문하지 않음
                vis[j] = vis[nx];   // 사다리 또는 뱀을 통해 이동하는 칸도 방문 표시 (주사위로 이동한 칸과 동일한 거리)
                q.push(j);  // 사다리 또는 뱀이 있는 곳은, 사다리 또는 뱀을 통해 이동한 칸을 q에 push
            }else{
                q.push(nx); // 주사위로 이동한 칸을 q에 push
            }
        }
    }

    cout << vis[100] - 1 << "\n";
}   
