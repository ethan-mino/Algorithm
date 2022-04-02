#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    bool exist[21];

    while(n--){
        string op; cin >> op;
        int v;
        if(op == "add"){
            cin >> v; 
            exist[v] = true;
        }else if(op == "remove"){
            cin >> v; 
            exist[v] = false;
        }else if(op == "check"){
            cin >> v; 
            if(exist[v]) cout << 1 << "\n"; else cout << 0 << "\n";
        }else if(op == "toggle"){
            cin >> v; 
            exist[v] = !exist[v]; 
        }else if(op == "all"){
            for(int i = 1; i <= 20; i++) exist[i] = true;
        }else{  // empty
            for(int i = 1; i <= 20; i++) exist[i] = false;
        }
    }
}