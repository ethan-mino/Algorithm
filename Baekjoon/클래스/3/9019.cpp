#include <bits/stdc++.h>
using namespace std;

#define pre first
#define op second

int dslr(int op, int n){
    if(op == 0){    // D 연산
        return (2*n) % 10000;
    }else if(op == 1){  // S 연산
        if(n == 0) return 9999;
        else return n - 1;
    }else {  // L, R 연산
        deque<int> q(4);
        for(int i = 3; i >= 0; i--){q[i] = n % 10; n /= 10;}
        if(op == 2) {q.push_back(q.front()); q.pop_front();}
        if(op == 3) {q.push_front(q.back()); q.pop_back();}

        int result = q[0];
        for(int i = 1; i < 4; i++) result = result * 10 + q[i];
        return result;
    }
}

char c[4] = {'D', 'S', 'L', 'R'};
pair<int, char> vis[10000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        fill(vis, vis + 10000, make_pair(-2, ' '));

        queue<int> q;
        q.push(a);
        vis[a] = {-1, ' '};
        while(!q.empty()){
            int cur = q.front(); q.pop();
            //cout << "cur : " << cur << "\n";
            for(int op = 0; op < 4; op++){
                int nx = dslr(op, cur);
                //if(nx == 9999) cout << vis[9999].pre << " " << vis[9999].op << "\n";
                //cout << "nx : " << nx << " " << q.size() << "\n";
                if(vis[nx].pre >= -1) continue; // 이미 방문한 경우, 방문하지 않음
                q.push(nx);
                vis[nx].pre = cur;
                vis[nx].op = c[op];
            }
        }

        // for(int i = 0; i < 10000; i++) {
        //     cout << i << " " << vis[i].pre << " " << vis[i].op << "\n";
        //     //if(vis[i].pre < - 1) cout << "asd \n";
        // }
        
        //cout << end << "\n";
        int cur = b;
        vector<char> ops;
        while(true){
            if(cur == a) break;
            ops.push_back(vis[cur].op);
            cur = vis[cur].pre;
        }

        reverse(ops.begin(), ops.end());
        for(auto c : ops) cout << c;
        cout << "\n";
    }
}   


/*
1
1234  3412

1 
1 9999

1
1 999

1
1 5000

3
1 9999
1 5000
3 4999


1 
5000 9999
*/
