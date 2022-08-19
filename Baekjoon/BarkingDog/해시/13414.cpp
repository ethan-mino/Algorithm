#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l; cin >> k >> l;
    map<string, int> m;
    for(int i = 0; i < l; i++){
        string num; cin >> num;
        m[num] = i;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < k; i++){
        if(i >= v.size()) break;
        cout << v[i].first << "\n";
    }
}   