#include <bits/stdc++.h>
using namespace std;

int linked[100][100];
int adj[100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)  // 인접 행렬 입력 받음
        for(int j = 0; j < n; j++)
            cin >> linked[i][j];

    for(int i = 0; i < n; i++){
        int vis[100];
        fill(vis, vis + 100, 0);

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nx = 0; nx < n; nx++){
                if(linked[cur][nx] == 0 || vis[nx] != 0) continue; // 인접하지 않거나 이미 방문한 경우 방문하지 않음
                q.push(nx);
                vis[nx] = 1;
            }
        }

        for(int j = 0; j < n; j++) adj[i][j] = vis[j];  // 경로 행렬에 기록
    }
    
    for(int i = 0; i < n; i++){ // 경로 행렬 출력
        for(int j =0 ; j < n; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}   
