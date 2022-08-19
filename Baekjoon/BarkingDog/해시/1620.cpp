#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    map<int, string> m2;

    for(int i = 1; i <= n; i++){
        string name; cin >> name;
        s2i[name] = i;
        i2s[i] = name;
    }

    while(m--){
        string query; cin >> query;
        int num = atoi(query.c_str());
        if(num){
            cout << i2s[num] << "\n";
        }else{
            cout << s2i[query] << "\n";
        }
    }
}   