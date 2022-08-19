#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000005;
int dat[MAX];
int head = 0, tail = 0; // head는 가장 앞에 있는 원소의 인덱스이고, tail은 가장 뒤에 있는 원소의 인덱스 + 1 (tail을 가장 마지막의 원소의 인덱스로 두어도 됨.)

int empty(){
    if (head == tail)
        return 1;
    else 
        return 0;
}

void push(int num){
     dat[tail++] = num;
}

int pop(){
    if(empty())
        return -1;
    else 
        return dat[head++];
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

int size(){
    return tail - head;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        if(s == "push"){
            int c;
            cin >> c;
            push(c);
        }else if(s == "pop"){
            cout << pop() << "\n";
        }else if(s == "size"){
            cout << size() << "\n";  
        }else if (s == "empty"){
            cout << empty() << "\n";
        }else if(s == "front"){
            cout << front() << "\n";
        }else if(s == "back"){
            cout << back() << "\n";
        }
    }
}