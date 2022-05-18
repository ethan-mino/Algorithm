#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> m;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string name, io; cin >> name >> io;
        if(io == "leave") m[name] = 0;
        else m[name] = 1;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    reverse(v.begin(), v.end());

    for(auto t : v) if(t.second) cout << t.first << "\n";
}   