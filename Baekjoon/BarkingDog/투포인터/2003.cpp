#include <bits/stdc++.h>
using namespace std;

int seq[10010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> seq[i];

    int st = 0, en = 0, sum = seq[0];
    int cnt = 0;

    while(true){
        while(sum < m) sum += seq[++en];
        if(sum == m) cnt++;

        if(st >= n || en >= n)  break;
        sum -= seq[st]; st++;
    }
    cout << cnt << "\n";
}   