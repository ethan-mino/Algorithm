#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    long long big = max(a, b);
    long long small = (big == a) ?  b : a;
    
    vector<long long> v;

    for(long long i = small + 1; i < big; i++)
        v.push_back(i);

    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for(auto e : v){
        cout << e << " ";
    }
}
