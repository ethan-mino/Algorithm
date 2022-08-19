#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> d;

    while(n--){
        string op;
        cin >> op;

        if(op == "push_front"){
            int c;
            cin >> c;
            d.push_front(c);
        }else if(op == "push_back"){
            int c;
            cin >> c;
            d.push_back(c);
        }else if(op == "pop_front"){
            if(d.empty()) cout << -1 << "\n";
            else {cout << d.front() << "\n"; d.pop_front(); }
        }else if(op == "pop_back"){
            if(d.empty()) cout << -1 << "\n";
            else {cout << d.back() << "\n"; d.pop_back();}
        }else if(op == "size"){
            cout << d.size() << "\n";
        }else if(op == "empty"){
            cout << d.empty() << "\n";
        }else if(op == "front"){
            if(d.empty()) cout << -1 << "\n";
            else cout << d.front() << "\n";
        }else if(op == "back"){
            if(d.empty()) cout << -1 << "\n";
            else cout << d.back() << "\n";
        }
    }
}
