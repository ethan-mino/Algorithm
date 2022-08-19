#include <bits/stdc++.h>
using namespace std;

#define v first
#define a second

int last = 1;   // 마지막 요소 + 1
pair<int, int> heap[200002];  // 절댓값 힙

int size(){return last -1;}
void swap(int a, int b){
    pair<int, int> temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void insert(int n){
    heap[last] = {n, abs(n)};
    int cur = last;
    
    while(true){
        int p = cur/2;
        //  부노 노드와 비교하여 절대값이 같고, 값이 더 작거나, 절대값이 더 작은 경우 swap
        if(p > 0 && 
        ((heap[cur].a < heap[p].a) || (heap[cur].a == heap[p].a && heap[cur].v < heap[p].v))){    
            swap(cur, cur/2); cur = cur/2;
        }else break;    // 부모 노드보다 더 작으면 더 이상 올라가지 않음
    }
    last++;
}

int pop_min(){
    pair<int, int> root = heap[1];
    heap[1] = heap[(last--) - 1];   // 마지막 요소를 루트로 이동
    int cur = 1;
    while(true){
        int left = cur * 2, right = cur * 2 + 1;
        if(right >= last && left < last){   // 왼쪽만 있는 경우
            if((heap[cur].a > heap[left].a) // 왼쪽과 절대값이 같은데, 왼쪽의 값이 더 작은 경우 또는 왼쪽의 절대값이 더 작은 경우 swap
            || (heap[cur].a == heap[left].a && heap[cur].v > heap[left].v)){
                swap(cur, left); cur = left;
            }
            else break;
        }else if(right < last){ // 오른쪽 자식도 있는 경우  
            // 왼쪽과 오른쪽 중, 절대값이 더 작은 자식 또는 절대값이 같은데, 값이 더 작은 자식
            int m = ((heap[left].a > heap[right].a) || (heap[left].a == heap[right].a && heap[left].v > heap[right].v)) ? right : left;
            if((heap[cur].a > heap[m].a) || (heap[cur].a == heap[m].a && heap[cur].v > heap[m].v)) {swap(cur, m); cur = m;}
            else break;
        }else break;    // 자식 노드가 없는 경우
    }

    return root.v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while(n--){
        int k; cin >> k;
        if(k == 0){
            if(size() > 0) cout << pop_min() << "\n";
            else cout << 0 << "\n";
        }else{
            insert(k);
        }
    }
}   
/*
20
2
1
1
-1
1
-1
-2
3
-3
4
0
0 
0
0
0
0
0
0
0
0
*/
