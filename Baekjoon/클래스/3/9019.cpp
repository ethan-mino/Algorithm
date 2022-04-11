#include <bits/stdc++.h>
using namespace std;

#define pre first
#define op second

char c[4] = {'D', 'S', 'L', 'R'};
pair<int, char> vis[10000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        fill(vis, vis + 10000, make_pair(-2, ' '));

        queue<int> q;
        q.push(a);
        vis[a] = {-1, ' '};
        bool end = false;
        while(!q.empty() && !end){
            int cur = q.front(); q.pop();

            for(int op = 0; op < 4; op++){
                int nx;
                if(op == 0){    // D 연산
                    nx = (2 * cur) % 10000;
                }else if(op == 1){  // S 연산
                    nx = (cur == 0) ? 9999 : cur - 1;
                }else if(op == 2){  // L, R 연산
                    nx = (cur % 1000) * 10 + (cur / 1000);
                }else{
                    nx = (cur / 10) + (cur % 10) * 1000;
                }

                if(vis[nx].pre >= -1) continue; // 이미 방문한 경우, 방문하지 않음
                q.push(nx);
                vis[nx].pre = cur;
                vis[nx].op = c[op];
                if(nx == b) end = true;
            }

        }

        int cur = b;
        list<char> ops;
        while(true){
            if(cur == a) break;
            ops.push_front(vis[cur].op);
            cur = vis[cur].pre;
        }

        for(auto c : ops) cout << c;
        cout << "\n";
    }
}   

/*
1
1234  3412

1 
1 9999

1
1 999

1
1 5000

3
1 9999
1 5000
3 4999


1 
5000 9999

1
5000 8456

1
0 8456
*/
