#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<string> a, b;
    int n, m;
    cin >> n >> m;

    for(int i =0; i < n; i++){
        string str; cin >> str; 
        a.insert(str);
    }

    for(int i =0; i < m; i++){
        string str; cin >> str; 
        b.insert(str);
    }

    vector<string> v(a.size() + b.size());
    auto iter = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
    v.erase(iter, v.end());
    
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
        
}

/*
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton
*/