#include <bits/stdc++.h>
using namespace std;

long long pop(priority_queue<int, vector<int>> & max_heap, 
priority_queue<int, vector<int>, greater<int>> & min_heap, map<int, int> & m, int op){
    long long top = LLONG_MAX;
    while(true){
        if(op == 0) {top = max_heap.top(); max_heap.pop();}
        if(op == 1) {top = min_heap.top(); min_heap.pop();}
        auto p = m.find(top);

        if(p != m.end()) { // 유효한 숫자인 경우
            if(p->second == 1) m.erase(p);
            else p->second--;
            break;   
        }
    }
    return top;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        priority_queue<int, vector<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        map<int, int> m;    // 유효한 숫자만을 저장하는 map

        while(k--){
            char c; int v; 
            cin >> c; cin >> v;

            if(c == 'I'){
                max_heap.push(v);
                min_heap.push(v);
                
                auto p = m.find(v);
                if(p == m.end()){   // map에 없는 숫자인 경우
                    m.insert({v, 1});
                }else{
                    p->second++;
                }
            }else{
                if(!m.empty()){
                    if(v == - 1){   // 최솟값 삭제
                        pop(max_heap, min_heap, m, 1);
                    }else{  // 최댓값 삭제
                        pop(max_heap, min_heap, m, 0);
                    }
                }
            }
        }

        if(m.size() > 0){
            int max1 = pop(max_heap, min_heap, m, 0);
            int min1;
            if(m.size() > 0){
                min1 = pop(max_heap, min_heap, m, 1);
            }else min1 = max1;
            cout << max1 << " " << min1 << "\n";
        }else   cout << "EMPTY\n";
    }
}   

/*
1
7
I 16
I -5643
D -1
D 1
D 1
I 123
D -1

1
9
I -45
I 653
D 1
I -642
I 45
I 97
D 1
D -1
I 333

1
5
I -45
I 30
I -30
I 100
D -1
*/
