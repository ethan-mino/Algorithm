// Created by 길민호 on 2022/09/17.

#include <bits/stdc++.h>
using namespace std;

map<int, int> vis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n, k; cin >> n >> k;
    for(int w, i = 0; i < n; i++){
        cin >> w;   // 샘터의 위치 입력 받음
        q.push(w);
        vis[w] = 1;
    }

    // * 각 집을 샘터에 가깝게 건설
    // * 각 샘터에서 step 칸 이동한 칸에 집을 건설하는 경우,
    // * 만약 100,00개의 샘터가 모두 100_000_000에 몰려 있다면, 단 한개의 샘터만 동작할 수 있으므로, 100_000 * 100_000번 반복해야함
    int builtCnt = 0;   // 건설된 집의 개수
    long long misfortune = 0; // 불행도
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int nxs[2] = {cur - 1, cur + 1};

        for(auto nx : nxs){
            if(vis[nx] != 0) continue;

            builtCnt++;
            vis[nx] = vis[cur] + 1;
            misfortune += vis[nx] - 1;
            q.push(nx);
            if(builtCnt == k) goto end;
        }
    }

    end :
    cout << misfortune << "\n";
}

/*
1 5
100000000
-> 15

1 5
-100000000
-> 15

2 100000
99999999 100000000
-> 5000050000
*/