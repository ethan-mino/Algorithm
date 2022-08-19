#include <bits/stdc++.h>
using namespace std;

map<int, bool> m;   // map

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        bool b; cin >> b;
        if(b) m[i] = b; // 명소의 위치만 저장
    }

    int cur = 0; // 도현이의 위치
    for(int i = 0; i < q; i++){
        int query; cin >> query;

        if(query == 1){ // 1번 연산
            int x; cin >> x;
            if(m[x - 1]) m.erase(x - 1);
            else m[x - 1] = true;
        }else if(query == 2){   // 2번 연산
            int x; cin >> x;
            cur = (cur + x) % n;    // MOD 연산으로 도현이의 위치 이동시킴
        }else{  // 3번 연산
            if(m.size() == 0) // 명소가 없는 경우
                cout << - 1 << "\n";    // -1 출력
            else {
                auto pos = m.lower_bound(cur);    // 도현이 다음의 명소의 위치
                if(pos == m.end()){   // 도현이 이후에 명소가 없는 경우
                    int step = (n - cur) + (*m.begin()).first; // 첫번째 명소까지의 거리
                    cout << step << "\n"; // 다음 명소는 첫번째 명소
                }else{  // 도현이 이후에 명소가 있는 경우
                    cout << (*pos).first - cur << "\n"; // 명소의 위치 - 도현이의 위치
                }
            }
        }
    }
}

/*
5 1
1 1 1 1 1
3

5 2
0 1 1 1 1
2 10
3

5 2
0 1 0 1 1
2 10
3
*/