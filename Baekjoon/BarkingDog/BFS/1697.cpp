#include <bits/stdc++.h>
using namespace std;

int board[100000];
int vis[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    vis[n] = 1;
    q.push(n);

    while(true){
        int cur = q.front(); q.pop();

        if(cur == k){
            cout << vis[cur] - 1;
            break;
        }
        
        if(cur - 1 >= 0 && vis[cur - 1] == 0) {vis[cur -1] = vis[cur] + 1; q.push(cur - 1);}
        if(cur + 1 <= 100000 && vis[cur + 1] == 0) {vis[cur + 1] = vis[cur] + 1; q.push(cur + 1);}
        if(2 * cur <= 100000 && vis[2 * cur] == 0) {vis[2 * cur]  = vis[cur] + 1; q.push(2 * cur);}
    }
}