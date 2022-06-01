#include <bits/stdc++.h>
using namespace std;

#define h first
#define k second

typedef pair<int, int> pii;
pii arr[500010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 본인보다 키가 큰 사람 중에서 s_num보다 k가 큰 사람
    
    int n, ans = 0; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].h >> arr[i].k;    // 키와 Ki를 입력 받음

    sort(arr , arr + n, greater<>());   // 키를 기준으로 내림차순 정렬

    multiset<int> group;    // 그룹의 인워수를 저장하는 set, 안워수가 중복될 수 있으므로 multiset을 사용

    for(int i = 0; i < n; i++){ // 키가 큰 학생부터 그룹을 할당시킴
        auto lower = group.lower_bound(arr[i].k);   // 인원 수가 Ki보다 크거나 같은 그룹 중 가장 인원 수가 작은 그룹을 찾는다. 
        if(lower == group.begin()){ // 찾지 못한 경우, 경우 새로운 그룹을 생성한다. 
            group.insert(1);
        }else{  // 찾은 경우, 해당 그룹보다 인원수가 작은 그룹에 학생을 할당시킨다.
            int size = (*prev(lower));  // 기존 인원 수
            group.erase(prev(lower));   // 기존 그룹을 삭제
            group.insert(size + 1); // 인원수를 1 증가시킨 후 set에 추가
        }
    }

    cout << group.size() << "\n";   // 그룹의 개수를 출력
}

/*
5
188 4
180 1
172 1
161 2
154 2
-> 3

5
160 1
161 1
162 1
163 1
164 1
-> 5

1
161 1
-> 1

2
161 2
170 2
-> 1

6
161 3
172 1
173 1
174 1
175 1
176 1
-> 5

5
161 5
170 1
172 1
173 5
175 3
-> 3

6
161 5
170 2
171 1
172 3
173 4
174 5
-> 2
*/