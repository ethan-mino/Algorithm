#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if(a.second.second == b.second.second)  return a.second.first < b.second.first; // 빈도수가 같은 경우
    return a.second.second > b.second.second;   // 빈도수가 높은 순으로
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c; cin >> n >> c;
    map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        auto p = m.find(t);

        if(p != m.end()) p->second.second++;
        else m.insert({t, {i, 1}});
    }

    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());

    stable_sort(v.begin(), v.end(), cmp);
    for(auto c : v){
        for(int i = 0; i < c.second.second; i++)
            cout << c.first << " "; 
    }
}    
