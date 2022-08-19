// Created by 길민호 on 2022/07/02.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 10001
int p[SIZE];

vector<int> Ancestor(int v){  // 정점의 모든 조상을 벡터에 담아 반환하는 함수
    vector<int> anc;    //
    int cur = v;    // v부터 시작
    while(cur != 1){
        anc.push_back(p[cur]);  // 부모 노드를 담음
        cur = p[cur];   // cur은 부모로 이동
    }
    return anc; // 조상 노드 반환
}

int tree_size(int root, vector<vector<int>>& c){   // root의 서브 트리의 크기를 구하는 함수
    if(c[root].size() == 0) return 1;  // leaf 노드인 경우

    // 자식 노드의 서브 트리 크기를 계산해서 더해줌
    int size = 0;
    for(auto v : c[root]) size += tree_size(v, c);
    return size + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int th = 1;
    while(t--){
        int v, e, a, b; cin >> v >> e >> a >> b;
        vector<vector<int>> c(v + 1);  // 자식 노드 번호를 저장하는 리스트

        for(int i = 0; i < e; i++){
            int parent, child; cin >> parent >> child;
            p[child] = parent;  // 각 정점의 부모 노드를 저장
            c[parent].push_back(child);    // 자식 노드 번호를 저장
        }

        vector<int> p_a = Ancestor(a);
        vector<int> p_b = Ancestor(b);

        sort(p_b.begin(), p_b.end());   // 이진 탐색을 위해 b 정점의 조상을 정렬

        int root = 0;   // 공통 조상의 번호
        for(int idx = 0; idx < p_a.size(); idx++){
             bool find = binary_search(p_b.begin(), p_b.end(), p_a[idx]);   // a 정점의 조상을 b 정점의 조상에서 찾음
             if(find) { // 찾은 경우
                 root = p_a[idx];
                 break;
             }
        }
        int size = tree_size(root, c);  // 공통 조상의 서브 트리 크기를 구함
        cout << "#" << th++ << " " << root << " " << size << "\n";
    }
}
