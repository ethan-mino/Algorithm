#include <bits/stdc++.h>
using namespace std;

#define num first
#define freq second
long long arr[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr + n); // 배열 정렬
    pair<long long, int> m = {0, INT_MIN};  // 배열 내의 최대 빈도수와 해당 숫자를 저장하는 변수
    int start = 0; // 연속된 숫자들의 첫 idx를 나타내는 변수
    
    while(start < n){
        int cur = start;
        while(cur < n && arr[cur] == arr[start]) cur++; // start부터 다른 숫자가 나올 때까지 cur 증가
    
        // cur이 n이거나 arr[cur] != arr[start]인 경우
        // start ~ cur - 1은 같은 수
        int f = cur - (start + 1); // arr[start]의 빈도수
        if(m.freq < f) m = {arr[start], f}; // 빈도수가 더 클 때만 업데이트(같을 때는 작은 수가 출력되어야 함)
        start = cur;    // cur부터 다시 빈도수 체크
    }

    cout << m.num; 
}   

/*
7
2 2 2 3 3 3 3
*/