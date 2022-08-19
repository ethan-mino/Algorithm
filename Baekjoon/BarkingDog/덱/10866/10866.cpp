#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int dat[2 * MAX + 1];
int head = MAX, tail = MAX; 

int size(){
    return tail - head;
}

int empty(){
    if(size() == 0)
        return 1;
    else 
        return 0;
}

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

int pop_front(){
    if(empty())
        return -1;
    else 
        return dat[head++];
}

int pop_back(){
   if(empty())
        return -1;
    else 
        return dat[--tail];
}

int front(){
    if(empty())
        return -1;
    else    
        return dat[head];
}

int back(){
    if(empty())
        return -1;
    else    
        return dat[tail - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string op;
        cin >> op;

        if(op == "push_front"){
            int c;
            cin >> c;
            push_front(c);
        }else if(op == "push_back"){
            int c;
            cin >> c;
            push_back(c);
        }else if(op == "pop_front"){
            cout << pop_front() << "\n";
        }else if(op == "pop_back"){
            cout << pop_back() << "\n";
        }else if(op == "size"){
            cout << size() << "\n";
        }else if(op == "empty"){
            cout << empty() << "\n";
        }else if(op == "front"){
            cout << front() << "\n";
        }else if(op == "back"){
            cout << back() << "\n";
        }
    }
}
