#include <bits/stdc++.h>
using namespace std;

#define left first
#define right second
#define length first
#define idx second
#define MAX 10010

int l[MAX], r[MAX], p[MAX];
int w[MAX];
int col[MAX];
int level[MAX];

int width(int v){
    if(w[v] != 0){
        return w[v];
    }else{
        if(l[v] != -1) w[v] += width(l[v]);
        if(r[v] != -1) w[v] += width(r[v]);
        w[v] += 1;
        return w[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ROOT = 0;
    for(int i = 1; i <= n; i++){
        int pn, ln, rn; cin >> pn >> ln >> rn;  // 부모, 왼쪽 자식, 오른쪽 자식의 번호 입력 받음
        l[pn] = ln; r[pn] = rn; // 부모의 왼쪽, 오른쪽 자식 설정
        p[ln] = pn; p[rn] = pn; // 왼쪽/오른쪽 자식의 부모 설정
    }

    for(int i = 1; i <= n; i++)
        if(p[i] == 0) ROOT = i;
    //cout << "r : " << ROOT << "\n";

    level[ROOT] = 1;   // root의 레벨은 1
    for(int v = 1; v <= n; v++) width(v);   // 각 정점을 루트로 하는 서브 트리의 너비 계산
    if(l[ROOT] == -1) col[ROOT] = 1;  // 루트의 왼쪽 자식이 없는 경우 루트의 열 번호는 1
    else col[ROOT] = w[l[ROOT]] + 1;  // 루트의 왼쪽 자식이 있는 경우, 루트의 열 번호는 왼쪽 자식의 너비 + 1

    queue<int> q;
    q.push(ROOT);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(l[cur] != -1){
            level[l[cur]] = level[cur] + 1;
            if(r[l[cur]] != -1) col[l[cur]] = col[cur] - w[r[l[cur]]] - 1;
            else col[l[cur]] = col[cur] - 1;
            q.push(l[cur]);
        }

        if(r[cur] != -1){
            level[r[cur]] = level[cur] + 1;
            if(l[r[cur]] != -1) col[r[cur]] = col[cur] + w[l[r[cur]]] + 1;
            else col[r[cur]] = col[cur] + 1;
            q.push(r[cur]);
        }
    }

    int max_level = *max_element(level, level + n + 1);
    pair<int, int> m = {INT_MIN, -1};

    for(int i = 1; i <= max_level; i++){
        int left = INT_MAX, right = INT_MIN;
        
        for(int j = 1; j <= n; j++){
            if(level[j] == i){
                left = min(left, col[j]);
                right = max(right, col[j]);
            }
        }

        int len = right - left + 1;
        if(len > m.length) m = {len, i};
    }
    
    cout << m.idx << " " << m.length << "\n";
}

// 정점 r을 루트로 하는 트리의 너비는 자식 서브 트리의 너비 + 1
// 왼쪽 자식(l)의 위치는 p[l]의 위치 - r[l]의 너비 - 1
// 오른쪽 자식(r)의 위치는 p[r]의 위치 + l[r]의 너비 + 1

/*
1
1 -1 -1
-> 1 1

4
1 2 -1
2 3 4
3 -1 -1
4 -1 -1
-> 3 3

3
1 -1 2
2 -1 3
3 -1 -1
-> 1 1

2
1 -1 2
2 -1 -1
-> 1 1

5
1 2 -1
2 3 -1
3 4 -1
4 5 -1
5 -1 -1
-> 1 1

5
1 2 -1
2 3 -1
3 4 5
4 -1 -1
5 -1 -1
-> 4 3

18
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 -1
18 -1 -1

19
17 1 6
1 8 -1
8 -1 -1
6 11 3
11 15 16
15 -1 -1
16 14 -1
13 12 10
14 -1 -1
12 5 2
5 9 -1
2 -1 -1
3 -1 -1
10 4 -1
4 18 -1
18 -1 7
7 -1 -1
9 -1 -1
19 17 13
-> 3 18

10
1 2 5
2 3 10
10 -1 -1
3 4 -1
4 -1 -1
5 6 -1
6 7 -1
7 8 -1
8 9 -1
9 -1 -1
*/