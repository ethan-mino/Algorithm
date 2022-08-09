#include <bits/stdc++.h>
using namespace std;

#define x first
#define dir second

deque<int> gears[4];
int dx[2] = {-1, 1};

void rotate(int n, int dir){
    // 첫번째 있던게 뒤로 가면 반시계(-1인 경우)
    // 뒤에 있던게 첫번째로 오면 시계(1인 경우)
    if(dir == 1){ // 시계 방향으로 회전
        gears[n].push_front(gears[n].back());
        gears[n].pop_back();
    }else{  // 반시계 방향으로 회전
        gears[n].push_back(gears[n].front());
        gears[n].pop_front();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i++){
        string str; cin >> str;
        deque<int> gear;
        for(int j = 0; j < 8; j++){
            gear.push_back(str[j] - 48);
        }
        gears[i] = gear;
    }

    int k, n, dir; cin >> k; 
    while(k--){
        cin >> n >> dir;
        int vis[4] = {0, 0, 0, 0};

        fill(vis, vis + 4, 0);
        
        vector<pair<int, int>> v;
        queue<pair<int, int>> q;
        vis[n - 1] = true;
        q.push({n - 1, dir});

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            v.push_back(cur);
            
            for(int i = 0; i < 2; i++){
                int nx = cur.x + dx[i];
                if(nx < 0 || nx > 4 || vis[nx] != 0) continue;
                if(i == 1 && gears[cur.x][2] == gears[nx][6]) continue;
                if(i == 0 && gears[cur.x][6] == gears[nx][2]) continue;

                vis[nx] = true;
                q.push({nx, {cur.dir * -1}});
            }
        }

        for(auto c : v)        
            rotate(c.x, c.dir);
    }

    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(gears[i].front() == 1)
            ans += pow(2, i);
    }

    cout << ans;
}

/*
10101111
01111101
11001110
00000010
0
*/