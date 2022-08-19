#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string, int> m;
        string name, type;
        for(int i =0 ; i < n; i++){
            cin >> name >> type;
            m[type]++;
        }
        int ans = 1;
        for(auto t : m)
            ans *= (t.second + 1);
        cout << ans - 1 << "\n";
    }
}   

// headgear 2
// eyewear 1