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

/*
    int N, s, e, i;
    int q[2000005];

    int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        string com;
        cin >> com;
        if(com == "push"){
        cin >> q[e++];
        } else if(com == "pop"){
        cout << (s == e ? -1 : q[s++]) << '\n';
        } else if(com == "size"){
        cout << e - s << '\n';
        } else if(com == "empty"){
        cout << (s == e) << '\n';
        } else if(com == "front"){
        cout << (s == e ? -1 : q[s]) << '\n';
        } else if(com == "back"){
        cout << (s == e ? -1 : q[e-1]) << '\n';
        }
    }
    }
*/