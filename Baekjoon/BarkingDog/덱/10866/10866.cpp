#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int dat[2 * MAX + 1];
int head = MAX, tail = MAX; // 큐에서는 앞쪽에서는 제거만 발생하고, 뒷쪽에서는 삽입만 발생하다보니 배열 내에서 실제 큐에 들어간 원소들이 차지하는 공간이 점점 오른쪽으로 이동하면서 확장하는 모양이었음. 
                            // 하지만, 덱에서는 양쪽에서 모두 삽입이 가능하기 때문에 양쪽으로 확장해야함. 
                            // 따라서 시작 지점을 0번지로 뒀을 경우 왼쪽으로 확장할 수 없기 때문에 시작 지점을 배열의 중간으로 두어야 함. 
                            // 따라서 배열의 크기는 2 * MAX + 1, head와 taildㅢ 초기 값이 0이 아니라 MAX


void push_front(){
    
}

void push_back(){

}

void pop_front(){

}

void pop_back(){

}

int front(){

}

int back(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

}
