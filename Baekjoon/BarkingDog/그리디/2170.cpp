#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int start, end;
}line;
line lines[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> lines[i].start >> lines[i].end;  //  선들의 정보 입력 받음

    sort(lines, lines + n, [](line a, line b) -> bool {return a.start < b.start;}); // 시작점을 기준으로 정렬

    int ans = 0;
    line cur = {(INT_MIN), INT_MIN};    // 현재 선의 정보
    for(auto line : lines){ // 각 선에 대해 반복
        if(cur.end >= line.start && cur.end < line.end){    // 겹치는 경우
            cur.end = line.end; // 현재 선의 끝점을 업데이트
        }else if(cur.end < line.start){ // 겹치지 않는 선을 만나면
            ans += cur.end - cur.start; // 현재 선의 길이를 더해줌
            cur = line; // 겹치지 않는 선으로 업데이트
        }
    }
    ans += cur.end - cur.start; // 마지막 선의 길이 더해줌
    cout << ans << "\n";
}   

/*
3
-2 3
2 5
3 5
-> 7
*/