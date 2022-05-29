#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> db;
map<int, int> dict;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n;
    for(int i = 0; i < n; i++){
        int p, l; cin >> p >> l;
        db.insert({l, p});
        dict[p] = l;
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        string op; cin >> op;

        if(op == "add"){
            int p, l; cin >> p >> l;
            db.insert({l, p});
            dict[p] = l;
        }else if(op == "recommend"){
            int x; cin >> x;
            if(x == -1){    // 가장 쉬운 문제의 번호를 출력
                cout << (*db.begin()).second << "\n";
            }else{  // x == 1, 가장 어려운 문제의 번호를 출력
                cout << (*prev(db.end())).second << "\n";
            }
        }else{  // op == "solved"
            int p; cin >> p;
            db.erase({dict[p], p});
            dict.erase(p);
        }
    }
}