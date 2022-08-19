#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    vector<string> v;
    for(int i = 0; i < str.size(); i++) v.push_back(str.substr(i, str.size() - i));
    sort(v.begin(), v.end());
    for(auto c : v) cout << c << "\n";
}   
