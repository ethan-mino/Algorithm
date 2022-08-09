#include <bits/stdc++.h>
using namespace std;

#define num first   // 숫자
#define f second    // 빈도수

int board[101][101];
int freq[101];  // 빈도수 배열

bool cmp(pair<int, int> n1, pair<int, int> n2){ // 행 또는 열의 정렬 기준
    if(n1.f == n2.f) return n1.num < n2.num;    // 빈도수가 같으면 수가 커지는 순으로
    else return n1.f < n2.f;    // 빈도수가 커지는 순으로
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, k;
    cin >> r >> c >> k;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> board[i][j]; //  배열 입력 받음

    int row = 3, col = 3, sec = 0;   // 행/열의 개수
    while(true){
        if(board[r - 1][c - 1] == k) break; // A[r][c]의 값이 k인 경우 중단
        if(sec == 100){sec = -1; break;}   // 100초가 지나도 A[r][c] != k이면, 중단

        int first, second;
        if (row >= col) {first = row; second = col;} else {first = col; second = row;}

        vector<int> l(first);
        for(int i = 0; i < first; i++){   // 각 행 또는 열에 대해 연산을 수행
            fill(freq, freq + 101, 0);  // 빈도수 배열을 0으로 초기화
            vector<pair<int, int>> sf;  // {수, 빈도수}를 저장하기 위한 벡터
            for(int j = 0; j < second; j++) 
                if(row >= col) freq[board[i][j]]++; // 빈도수 증가
                else freq[board[j][i]]++;
            for(int j = 1; j <= 100; j++) if(freq[j] != 0) sf.push_back({j, freq[j]});   // 각각의 {수, 빈도수}를 벡터에 저장 (수/빈도수 0은 무시)

            sort(sf.begin(), sf.end(), cmp);    // {수, 빈도수}의 벡터를 정렬 기준에 따라 정렬
            for(int j = 0; j < sf.size(); j++) 
                if(row >= col) {board[i][j*2] = sf[j].num; board[i][j*2 + 1] = sf[j].f;} // 벡터를 정렬하여 다시 행 또는 열에 기록 (최대 100개)
                else {board[j*2][i] = sf[j].num; board[j*2 + 1][i] = sf[j].f;}
                
            l[i] = (sf.size() >= 50) ? 100 : sf.size() * 2;   // 정렬된 행 또는 열의 크기, 크기가 100을 넘어가는 경우 나머지는 버림
        }
        
        second = *max_element(l.begin(), l.end());  // 행 또는 열의 최대 크기
        for(int i = 0; i < first; i++) // 가장 큰 행 또는 열의 크기에 맞춰 모든 행 또는 열의 나머지 부분에 0을 채움
            for(int j = l[i]; j < second; j++)
                if(row >= col) board[i][j] = 0;
                else board[j][i] = 0;

        if (row >= col) {col = second;} else {row = second;}  // 업데이트 된 행 또는 열의 크기를 다시 row 또는 col에 저장

        sec++;
    }     

    cout << sec;       
}

/*
1 2 3
1 2 1
2 1 3
3 1 1 

1 2 3
100 100 100
100 100 100
100 100 100
*/