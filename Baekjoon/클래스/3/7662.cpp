#include <bits/stdc++.h>
using namespace std;
void pv(string desc, vector<int> arr){
    cout << desc << " : ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insert(deque<int>& q, int n){
    if(q.size() == 0) { // q에 원소가 없는 경우
        q.push_back(n); // 마지막에 push
    }else if(!q.empty() && q.back() <= n){  // back 요소보다 크거나 같은 경우, back에 push
        q.push_back(n);
    }else if(!q.empty() && q.front() >= n){ // front 요소보다 작거나 같은 경우, front에 push
        q.push_front(n);
    }else{
        int left = 0, right = q.size() - 1;
        int mid = (left + right) / 2;
        while(left <= right){
            mid = (left + right) / 2;
            if(q[mid] <= n && n <= q[mid + 1])break;
            else if(q[mid] < n) left = mid + 1;
            else right = mid - 1;
        }
        q.insert(q.begin() + (mid + 1), n);
    }
}

int pop_min(deque<int>& q){
    int m = q.front();
    q.pop_front();
    return m;
}

int pop_max(deque<int>& q){
    int m = q.back();
    q.pop_back();
    return m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        deque<int> q;
        while(k--){
            char c; int v; 
            cin >> c; cin >> v;

            if(c == 'I'){
                insert(q, v);
            }else{
                if(q.size() > 0){
                    if(v == -1) pop_min(q);    // 최솟값 삭제
                    else pop_max(q);
                }
            }
            // cout << "q : ";
            // for(int i = 0; i < q.size(); i++) cout << q[i] << " " ;
            // cout << "\n";
        }
        if(q.size() > 0){cout << q.back() << " " << q.front();} 
        else cout << "EMPTY" << "\n";
    }
}   

// 4

  

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

// -45
// 653 -45
// -45
// -45 -642
// 45 -45 -642
// 97 45 -45 -642
// 45 - 45 -642
// 45 -45
// 333 45 -45