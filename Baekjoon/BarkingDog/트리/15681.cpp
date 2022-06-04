#include <bits/stdc++.h>
using namespace std;

// BFS 수행 후, 각 정점의 부모 노드를 찾음
// 자식이 없는 트리의 서브트리의 크기를 1로 설정
// 부모 서브트리의 크기는 자식 서브 트리의 합 + 1

int p[100010];  // p[i]는 i번째 정점의 부모 노드 번호
int s[100010]; // s[i]는 i번째 정점을 루트로 하는 서브트리의 크기
int n, r, q; 

int tree_size(vector<vector<int>>& linked, int v){   // 정점 v를 루트로 하는 서브 트리 크기를 반환하는 함수
    if(s[v] != 0){  // 이미 서브 트리의 크기가 계산된 경우
        return s[v];
    }else{  // 서브 트리의 값이 계산되지 않은 경우
        int sum = 0;    // 정점 v를 루트로 하는 서브 트리의 크기
        for(auto nxt : linked[v]){  // 자식 서브 트리의 크기 합을 구함
            if(nxt == p[v]) continue;   // 부모 노드인 경우 continue
            sum += tree_size(linked, nxt);  
        }
        s[v] = sum + 1; // 루트를 포함 시킴
        return s[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> q;
    
    vector<vector<int>> linked(n + 1);  // 인접 리스트
    for(int i = 0; i < n - 1; i++){ // 인접 리스트 입력 받음
        int u, v; cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }

    // BFS 수행
    queue<int> q1;
    q1.push(r);
    p[r] = -1;

    while(!q1.empty()){
        int cur = q1.front(); q1.pop();
        
        bool leaf = true;
        for(auto nxt : linked[cur]){
            if(nxt == p[cur]) continue;
            leaf = false;   // 인접한 노드 중 방문하지 않은 노드가 존재하는 경우 leaf 노드가 아님
            q1.push(nxt);
            p[nxt] = cur;
        }
        if(leaf) s[cur] = 1;    // leaf 노드인 경우 서브 트리의 크기를 1로 설정
    }

    while(q--){
        int v; cin >> v;
        cout << tree_size(linked, v) << "\n";   // 정점 v를 루트로 하는 서브 트리의 크기 출력
    }
}