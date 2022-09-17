// Created by 길민호 on 2022/09/17.
#include <bits/stdc++.h>
using namespace std;

#define w first
#define v second

int n, ans = 0;
vector<pair<int, int>> children[10001];

// * 트리의 한 쪽 끝은 단말 노드가 되어야 함.
// * 다른 한 쪽 끝은 일반 노드도 될 수 있음.
int distDiameter(int root){
    vector<int> dist(2, 0); // 자식 중 leaf 노드에서 자식 노드까지의 거리가 가장 긴 두 노드의 거리 저장

    for(auto child : children[root]){   // root의 자식 노드를 확인
        int toChild = distDiameter(child.v);  // 자식 노드의 자손 중 임의의 leaf 노드 부터, 자식 노드까지의 최대 거리
        int toRoot = toChild + child.w; // root의 거리 = 자식 노드까지의 최대 거리 + 자식과 rooot 노드의 가중치

        if(dist[0] < toRoot) {
            dist[1] = dist[0];
            dist[0] = toRoot;
        }else if(dist[1] < toRoot)
            dist[1] = toRoot;
    }

    int rootDiameter = 0;
    // root 노드까지의 거리 중 두 개를 선택하여 트리의 지름으로 결정
    for(int i = 0; i < 2; i++)
        rootDiameter += dist[i];

    // 트리의 지름 중 가장 긴 것 저장
    ans = max(rootDiameter, ans);
    return dist[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i =0 ; i < n - 1; i++){
        int p, c, w; cin >> p >> c >> w;
        children[p].push_back({w, c});
    }

    distDiameter(1);
    cout << ans << "\n";
}

/*
12
1 2 6
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
-> 46

2
1 2 3
-> 3

5
1 2 3
2 3 5
3 4 1
3 5 7
-> 15

6
1 2 3
1 3 2
2 4 5
4 7 1
4 8 7
-> 17

2
1 2 0
-> 0

5
1 2 1
1 3 2
1 4 3
1 5 4
-> 4
*/