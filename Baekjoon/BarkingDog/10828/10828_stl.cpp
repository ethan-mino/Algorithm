#include <bits/stdc++.h>
using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int opNum;
    cin >> opNum;

    stack<int> dat;

    while(opNum--){
        string op;
        cin >> op;

        if(op == "push"){
            int data;
            cin >> data;
            dat.push(data);
        }else if(op == "pop"){
            if(dat.size() == 0){
                cout << -1 << "\n";
            }else{
                cout << dat.top() << "\n";
                dat.pop();
            }
        }else if(op == "size"){
            cout << dat.size() << "\n";
        }else if(op == "empty"){
            cout << dat.empty() << "\n";
        }else if(op == "top"){
            if(dat.size() == 0){
                cout << -1 << "\n";
            }else {
                cout << dat.top() << "\n";
            }
        }
    }
}