// Created by 길민호 on 2022/09/18.

#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>> temp){
    int n = temp.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j] == -1) cout << ".";
            else cout << temp[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 벡터를 회전 시켜주는 함수
vector<vector<int>> rotate(vector<vector<int>> board){
    int n = board.size();

    vector<vector<int>> temp(n, vector<int>(n));
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            temp[y][n - x - 1] = board[x][y];

    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int lockSize = lock.size(); // 입력 받은 자물쇠의 크기
    int keySize = key.size();   // 입력 받은 키의 크기
    int newLockSize = lockSize + 2 * (keySize - 1); // 새로운 자물쇠의 크기

    vector<vector<int>> newLock(newLockSize, vector<int>(newLockSize, -1)); // 새로운 크기의 자물쇠를 생성하고, -1을 채움 (-1은 자물쇠를 벗어남을 의미)
    for(int i = keySize - 1; i < keySize - 1 + lockSize; i++)   // 새로운 자물쇠의 중앙에 기존 자물쇠를 복사
        for(int j = keySize - 1; j < keySize - 1 + lockSize; j++)
            newLock[i][j] = lock[i - (keySize - 1)][j - (keySize - 1)];

    // printBoard(newLock);

    // newLock의 각 좌표의 왼쪽 상단에 key의 왼쪽 상단을 두고
    // key를 rotate하며 일치하는 지 확인
    for(int x = 0; x < newLockSize - (keySize - 1); x++){
        for(int y = 0; y < newLockSize - (keySize - 1); y++){
            for(int r = 0; r < 4; r++){
                vector<vector<int>> tempLock(newLockSize, vector<int>(newLockSize));    // 임시 Lock (newLock과 동일한 크기)
                copy(newLock.begin(), newLock.end(), tempLock.begin()); // newLock을 tempLock에 복사

                key = rotate(key);  // 키를 회전시킴
                bool match = true;  // newLock과 key와 겹치는 부분이 맞물리는 지 나타내는 flag 변수

                // newLock과 key와 겹치는 부분이 맞물리는 지 확인
                for(int i = 0; i < keySize; i++){
                    for(int j = 0; j < keySize; j++){
                        int lockValue = newLock[x + i][y + j];
                        int keyValue = key[i][j];

                        if(lockValue == -1) continue;   // 자물쇠를 벗어나는 좌표인 경우 continue
                        if(lockValue == keyValue) { // 키와 자물쇠가 맞물리지 않는 경우 match를 false로 설정
                            match = false;
                            goto escape;
                        }
                        tempLock[x + i][y + j] = 1; // 키와 맞물렸으므로, 1로 설정 (즉, 채움)
                    }
                }

                escape :
                if(match) { // newLock과 key와 겹치는 부분이 맞물리는 경우
                    bool open = true;   // newLock의 맞물리지 않은 부분이 없어, 자물쇠를 열 수 있는지 나타내는 Flag 변수

                    // newLock의 맞물리지 않은 부분이 있는 지 확인
                    for(int i = 0; i < newLockSize; i++)
                        for(int j = 0; j < newLockSize; j++)
                            if(tempLock[i][j] == 0) open = false;   // 비어 있는 부분이 있다면 open을 false로 설정 (-1은 자물쇠를 벗어났음을 의미하므로 영향 X)

                    if(open) return true;   // 열 수 있다면 true를 반환
                }
            }
        }
    }
    return false;
}