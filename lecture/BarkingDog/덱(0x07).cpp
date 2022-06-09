#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;   // 큐에서는 앞쪽에서는 제거만 발생하고, 뒷쪽에서는 삽입만 발생하다보니 배열 내에서 실제 큐에 들어간 원소들이 차지하는 공간이 점점 오른쪽으로 이동하면서 확장하는 모양이었음.
                            // 하지만, 덱에서는 양쪽에서 모두 삽입이 가능하기 때문에 양쪽으로 확장해야함. 
                            // 따라서 시작 지점을 0번지로 뒀을 경우 왼쪽으로 확장할 수 없기 때문에 시작 지점을 배열의 중간으로 두어야 함. 
                            // 따라서 배열의 크기는 2 * MAX + 1, head와 taildㅢ 초기 값이 0이 아니라 MAX

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail - 1];
}

void test(){
  push_back(30); // 30
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 30
  push_front(25); // 25 30
  push_back(12); // 25 30 12
  cout << back() << '\n'; // 12
  push_back(62); // 25 30 12 62
  pop_front(); // 30 12 62
  cout << front() << '\n'; // 30
  pop_front(); // 12 62
  cout << back() << '\n'; // 62
}

int main(void){
  test();
}