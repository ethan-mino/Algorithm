#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int n;
    int idx;
}elem;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;

    while(n--){
        int c;
        cin >> c;
        arr.push_back(c);
    }

    int cnt = 0;
    stack<elem> s;

    elem e; e.n = 1000000001; e.idx = n;
    s.push(e);

    for(int i = n - 1; i >= 0; i--){
        while(arr[i] > s.top().n){
            s.pop();
        }

        cnt += s.top().idx - i - 1;
        elem t; t.idx = i; t.n = arr[i];
        s.push(t);
    }

    cout << cnt;
}
