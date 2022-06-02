#include <bits/stdc++.h>
using namespace std;

#define dist first
#define th second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c; cin >> c;

    while(c--){
        int n;
        cin >> n;

        list<int> l1[100001];
        pair<int, int> vis[100001] = {};

        for(int i = 1; i <= n; i++){
            int v;  cin >> v;
            l1[i].push_back(v);  // 선택한 팀원을 현재 학생의 인접리스트에 추가
        }

        int ans = 0;    // 팀에 속한 학생들의 수

        for(int i = 1; i <= n; i++){
            if(vis[i].dist == 0){
                queue<int> q;
                q.push(i);
                vis[i].dist = 1;
                vis[i].th = i;

                while(!q.empty()){
                    int cur = q.front(); q.pop();

                    while(!l1[cur].empty()){
                        int adj = l1[cur].front(); l1[cur].pop_front();   // cur에 인접한 노드, 방문한 노드는 

                        if(vis[adj].dist == 0){  // 인접하지만, 방문하지 않은 노드 모두 큐에 push
                            q.push(adj);  
                            vis[adj].dist = vis[cur].dist + 1;
                            vis[adj].th = vis[cur].th;
                        }else if(vis[adj].dist != 0 && vis[cur].th == vis[adj].th){  // 인접하지만, 현재 탐색에서 방문한 노드라면 -> 싸이클
                            ans += vis[cur].dist - vis[adj].dist + 1;   // 싸이클 길이만큼 팀에 속한 학생 수 증가 
                        }
                    }
                }
            }
        }

        cout << n - ans<< "\n"; // 전체 학생 수 - 팀이 정해진 학생 수
    }
}

/*
1
7
3 1 3 7 3 4 6
-> 3

1
8
1 2 3 4 5 6 7 8
-> 0

1
2
2 1
-> 0

1
4
2 3 4 1
-> 0

1
2
1 2
-> 0

1
3
2 3 3
-> 2

1
5
1 1 1 1 1
-> 4

1
10
10 2 1 6 8 1 10 3 4 1
-> 7

1
8
2 3 4 1 6 7 8 5
-> 0

1
9
2 3 4 5 6 7 8 1 2
-> 1
*/