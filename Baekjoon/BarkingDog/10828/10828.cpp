#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;
int dat[MAX];
int pos = 0 ;

void push(int data){
    dat[pos++] = data;
}

int size(){
    return pos;
}

int empty(){
    if(pos == 0)
        return 1;
    else 
        return 0;
}

int top(){
    if(empty())
        return -1;
    else
        return dat[pos - 1];
}

int pop(){
    if(empty())
        return -1;
    else
        return dat[--pos];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int opNum;
    cin >> opNum;

    while(opNum--){
        string op;
        cin >> op;

        if (op == "push"){
            int data;
            cin >> data;
            push(data);            
        }else if(op == "pop"){
            cout << pop() << '\n';
        }else if(op == "size"){
            cout << size() << '\n' ;
        }else if(op == "empty"){
            cout << empty() << '\n';
        }else if(op == "top"){
            cout << top() << '\n';
        }
    }
}