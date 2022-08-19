#include <bits/stdc++.h>
using namespace std;

int last = 1;   // 마지막 요소 + 1
int heap[2000002];  // 최대 힙

void swap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

int size(){
    return last -1;
}

void insert(int n){
    heap[last] = n;
    int cur = last;
    
    while(true){
        int p = cur/2;
        if(p > 0 && heap[cur] > heap[p]){    //  부노 노드와 비교
            swap(cur, cur/2); cur = cur/2;
        }else break;    // 부모 노드보다 더 작으면 더 이상 올라가지 않음
    }
    last++;
}

int pop_max(){
    int root = heap[1];
    heap[1] = heap[(last--) - 1];   // 마지막 요소를 루트로 이동
    int cur = 1;
    while(true){
        int left = cur * 2, right = cur * 2 + 1;
        if(right >= last && left < last){   // 왼쪽만 있는 경우
            if(heap[cur] < heap[left]){swap(cur, left); cur = left;}
            else break;
        }else if(right < last){ // 오른쪽 자식도 있는 경우  
            int m = (heap[left] < heap[right]) ? right : left;
            if(heap[cur] < heap[m]) {swap(cur, m); cur = m;}
            else break;
        }else break;    // 자식 노드가 없는 경우
    }
    return root;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    while(n--){
        int k; cin >> k;
        if(k == 0){
            if(size() > 0) cout << pop_max() << "\n";
            else cout << 0 << "\n";
        }else{
            insert(k);
        }
        for(int i = 1; i <= size(); i++)    cout << heap[i] << " ";
        cout << "\n";
    }
}   
