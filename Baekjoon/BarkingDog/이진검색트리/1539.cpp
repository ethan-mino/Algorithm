#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    set<int> s;
    map<int, int> m;
    
    long long ans = 0;
    for(int i = 0 ; i < n; i++){
        int c; cin >> c;
        if(m.size() == 0) {
            m[c] = 1;
        }else{
            auto lower = s.lower_bound(c);

            if(lower == s.end()){
                m[c] = m[(*prev(lower))] + 1;
            }else if(lower == s.begin()){
                m[c] = m[(*lower)] + 1;
            }else{
                m[c] = max(m[(*prev(lower))], m[(*lower)]) + 1;
            }
        }

        ans += m[c];
        s.insert(c);
    }
    cout << ans << "\n";
}

// 1 2 3 4 5 6 7 8 9 
// 1 3 4 9 