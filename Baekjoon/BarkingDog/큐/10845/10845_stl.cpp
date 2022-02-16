#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;

    while(n--){
        string s;
        cin >> s;

        if(s == "push"){
            int c;
            cin >> c;
            q.push(c);
        }else if(s == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }else if(s == "size"){
            cout << q.size() << "\n";  
        }else if (s == "empty"){
            cout << q.empty() << "\n";
        }else if(s == "front"){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }else if(s == "back"){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }

}
