#include <bits/stdc++.h>

using namespace std;

// 원소를 배열로 관리하고 pre와 nxt에 이전과 다음 원소의 포인터 대신 배열 상의 인덱스를 저장하는 방식으로 구현한 연결 리스트. 
// 메모리 누수때문에 실무에서 사용할 수 없는 방식이지만, 코딩 테스트에서는 일번적인 연결 리스트보다 구현 난이도가 낮고 시간 복잡도가 동일.
// 알고리즘 문제에서는 insert의 횟수에 제한이 있기 마련이기 때문에, 배열을 넉넉히 잡아서 연결 리스트를 구현

// pre와 nxt의 값이 -1이면 해당 원소의 이전/다음 원소가 존재하지 않는다는 의미 
// unused는 현재 사용되지 않는 인덱스, 즉 새로운 원소가 들어갈 수 있는 인덱스
// 길이가 필요하다면 len 변수를 두고 원소가 추가될 때 1 증가, 제거될 때 1 감소시키면 됨
// 0번지는 연결리스트의 시작 원소로 고정되어 있음. 0번지는 값이 들어가지 않고 단지 시작점을 나타내기 위한 dummy node
// 실제로 값이 있는 것은 아니지만 관념적으로 연결 리스트의 제일 앞에 원소가 하나 있다고 생각해야함. 이러한 dummy node가 없으면 삽입과 삭제 등의 기능을 구현할 때 원소가 아예 없는 경우에 대한 예외 처리를 해야함.

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int targetIdx, int data){
    int idx = 0;    // 몇번째 요소인지 나타내는 변수
    int curAddr = 0; // 현재 요소의 배열상 idx
    int nxtAddr = nxt[curAddr]; // 다음 요소의 배열상 idx

    while(idx < targetIdx){ // 삽입하고자 하는 위치 바로 이전 원소까지 이동
        curAddr = nxtAddr;
        nxtAddr = nxt[curAddr];
        idx++;
    }

    dat[unused] = data;
    nxt[unused] = nxtAddr;
    pre[unused] = curAddr;

    nxt[curAddr] = unused;  // 삽입한 요소 이전 요소의 nxt를 삽입한 요소의 addr로 변경
    if(nxtAddr != -1) pre[nxtAddr] = unused;    // 삽입한 요소 다음 요소의 pre를 삽입한 요소의 add로 변경 (마지막에 요소를 삽입한 경우, nxtAddr이 -1)
    unused++;
}

void erase(int targetIdx){
    int idx = 0;    // 몇번째 요소인지 나타내는 변수
    int curAddr = 0; // 현재 요소의 배열상 idx
    int nxtAddr = nxt[curAddr];

    while(idx < targetIdx){ // 제거하고자 하는 위치 바로 이전 원소까지 이동
        curAddr = nxtAddr;
        nxtAddr = nxt[curAddr];
        idx++;
    }
    
    nxt[curAddr] = nxt[nxtAddr];    // 제거 요소 이전 요소의 nxt를 제거한 요소의 다음 요소의 addr로 변경
    pre[nxt[curAddr]] = curAddr;    // 제거 요소 다음 요소의 pre를 제거한 요소의 이전 요소의 addr로 변경

    unused++;
}

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printList(){
    printArr(dat, 10);
    printArr(pre, 10);
    printArr(nxt, 10);
    cout << "\n\n";
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 10 40(address=3)
  traverse();
  insert(1, 20); // 30 20(address=4) 10 40
  traverse();
  insert(4, 70); // 30 20 10 40 70(address=)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 10 40 70
  traverse();
  erase(2); // 30 10 70
  traverse();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}