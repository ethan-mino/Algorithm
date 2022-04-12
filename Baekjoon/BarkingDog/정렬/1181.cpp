#include <bits/stdc++.h>
using namespace std;

set<string> s;

bool cmp(const string& a, const string& b){
    int len1 = a.size(), len2 = b.size();
    if(len1 == len2) return a < b;
    else return len1 < len2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; 
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        s.insert(str);
    } 
    
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), cmp);
    for(auto c : v) cout << c << "\n";
}   
