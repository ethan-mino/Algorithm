#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
char dat[MAX];
int pre[MAX];
int nxt[MAX];
int unused = 1;

void initialize(){
    fill(pre, pre + MAX, -1);
    fill(nxt, nxt + MAX, -1);
}

int moveCursor(bool right, int cursor){
    if (right){
        if(nxt[cursor] != -1)
            cursor = nxt[cursor];
    }else{
        if(pre[cursor] != -1)
            cursor = pre[cursor];
    }
    return cursor;
}

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = unused;
  
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  nxt[pre[addr]] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
    int cur = nxt[0];

    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    initialize();   // 리스트 초기화

    string content; 
    cin >> content; // 문장을 입력 받음

    int cursor = 0;  // 현재 커서의 왼쪽 문자의 배열상 idx

    for(int i = 0; i < content.length(); i++){
        insert(cursor, content[i]);
        cursor++;
    }

    int iter;   
    cin >> iter;    // 입력할 명령어의 개수 입력 받음
    
    while(iter--){    // 반복 수만큼 명령 실행
        char inst; // 명령어 입력 받음
        cin >> inst;

        switch(inst){
            case 'L' : cursor = moveCursor(false, cursor);
            break;
            case 'D' : cursor = moveCursor(true, cursor);
            break;
            case 'B' :       
                if (pre[cursor] != -1) {
                    erase(cursor);
                    cursor = pre[cursor];
                }
            break;
            case 'P' :
                char add;
                cin >> add;
                insert(cursor, add);
                cursor = nxt[cursor];
                break;
         }
    }

    traverse();
}


  