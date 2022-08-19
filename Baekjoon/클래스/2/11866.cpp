#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> l;
    for(int i = 1; i <= n; i++)
        l.push_back(i);


    auto cursor = l.begin();
    vector<int> v;
    while(!l.empty()){
        for(int i = 0; i < k -1; i++) {
            if(cursor == l.end()){
                cursor = l.begin(); 
            }
            cursor++;
            if(cursor == l.end()){
                cursor = l.begin(); 
            }
        }
        v.push_back(*cursor);
        cursor = l.erase(cursor); 
    }

    cout << "<";
    for(int i = 0; i < n; i++) {
        cout << v[i];
        if(i < n-1) cout << ", ";
    }
    cout << ">";
}
