#include <bits/stdc++.h>
using namespace std;

int dat[1000010];
int head = 0, tail = 0;

int empty(){
    return head == tail;
}
int pop(){
    if(empty())
        return -1;
    else
        return dat[head++];
}

void push(int num){
    dat[tail++] = num;
}

int front(){
    return dat[head];
}

int back(){
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

    for(int j = 1; j <= n; j++){
        push(j);
    }   

    while(size() > 1){
        pop();
        int c = pop();
        push(c);
    }

    cout << front();
}


