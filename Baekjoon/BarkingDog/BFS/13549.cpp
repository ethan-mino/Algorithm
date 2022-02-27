#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
int vis[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    vis[n] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if (cur == k){
            cout << vis[cur] - 1<< "\n";
            break;
        }

        int nx[3] = {cur * 2, cur - 1, cur + 1};    // cur * 2가 0초 후에 이동하므로 제일 먼저 확인하도록 함.
                                                    
        for(auto e : nx){
            int nx_vis = (e == cur * 2) ? vis[cur] : vis[cur] + 1;
            if(e >= 0 && e < MAX && vis[e] == 0) {
                vis[e] = nx_vis; 
                q.push(e);
            }
        }
    }
}