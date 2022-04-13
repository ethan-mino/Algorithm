#include <bits/stdc++.h>
using namespace std;

#define num first
#define pre second

pair<int, int> d[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    d[1] = {0, -1}; 
    for(int i = 2; i <= n; i++){
        d[i] = {d[i - 1].num + 1, i - 1};
        if(i % 3 == 0) if(d[i].num > d[i/3].num + 1) d[i] = {d[i/3].num + 1, i / 3};
        if(i % 2 == 0) if(d[i].num > d[i/2].num + 1) d[i] = {d[i/2].num + 1, i / 2};
    }

    cout << d[n].num << "\n" << n << " ";
    int cur = n;
    while(d[cur].pre != -1){
        cout << d[cur].pre << " ";
        cur = d[cur].pre;
    }
}   
