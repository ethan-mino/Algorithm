#include <bits/stdc++.h>
using namespace std;

#define MAX 10010
#define REMAIN first
#define OP second

int w_t[MAX];    // 각 작업의 남은 시간
int in[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> linked(n + 1);

    for(int v = 1; v <= n; v++){
        int t, num; cin >> w_t[v] >> num;
        for(int u, j = 0; j < num; j++){
            cin >> u; 
            linked[u].push_back(v);
            in[v]++;
        }
    }
    
    set<pair<int, int>> q;
    for(int v = 1; v <= n; v++) if(in[v] == 0) q.insert({w_t[v], v});

    int ans = 0;    // 모든 작업을 완료하기 위한 최소 시간
    while(!q.empty()){
        pair<int, int> cur = *q.begin(); q.erase(q.begin());
        set<pair<int, int>> temp;

        for(auto inf : q) {
            inf.REMAIN -= cur.REMAIN;
            if(inf.REMAIN < 0) inf.REMAIN = 0;
            temp.insert(inf);
        }

        q.clear();
        for(auto t : temp)
            q.insert(t);

        ans += cur.REMAIN;  

        for(auto nxt : linked[cur.OP]){
            in[nxt]--;
            if(in[nxt] == 0) q.insert({w_t[nxt], nxt});
        }
    }
    cout << ans << "\n";
}

// 선행 관계만 만족한다면 최소 시간에 작업을 완료할 수 있는가?
// 선행 관계에 있는 작업들은 병행이 가능

// 큐의 정점들은 수행중인 작업들을 의미
// 큐에서 빠져나온 것은 작업이 완료되었음을 의미

/*
7
1 0
2 0 
3 0 
4 0 
5 0
6 0
7 1
*/