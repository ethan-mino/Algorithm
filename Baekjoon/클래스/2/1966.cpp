#include <bits/stdc++.h>
using namespace std;

#define idx first
#define p second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c; cin >> c;
    while(c--){
        int n, m;
        cin >> n >> m;

        deque<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            pair<int, int> t; 
            t.idx = i; cin >> t.p;
            q.push_back(t);
        }
            
        int cnt = 0;
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop_front();
            
            if(!q.empty()){
                bool flag = false;

                for(int i = 0; i < q.size(); i++)
                    if(q[i].p > cur.p) flag = true;

                if (flag){ // 우선순위가 높은 문서가 큐에 존재하는 경우
                    q.push_back(cur);
                }else{  // 존재하지 않는 경우
                    cnt++;
                    if (cur.idx == m){
                        cout << cnt << "\n";
                        break;
                    }
                }
            }else{
                cout << ++cnt << "\n";
            }
        }
    }
}

/*
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
*/

