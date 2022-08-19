#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
int in[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> linked(n + 1);

    for(int i = 0; i < m; i++){
        int s; cin >> s;
        vector<int> o(s);
        for(int j = 0; j < s; j++){
            cin >> o[j];
        }
        for(int j = 0; j < s - 1; j++){
            int u = o[j], v = o[j + 1];
            in[v]++;
            linked[u].push_back(v);
        }
    }

    queue<int> q;   // indegree가 0인 정점들을 담는 큐
    vector<int> result; // 위상 정렬 결과
    for(int v = 1; v <= n; v++)
        if(in[v] == 0) q.push(v);
        
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);

        for(auto nxt : linked[cur]){
            in[nxt]--;
            if(in[nxt] == 0) q.push(nxt);
        }
    }

    if(result.size() != n) cout << 0 << "\n";
    else{
        for(auto r : result) cout << r << "\n";
    }
}