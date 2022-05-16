#include <bits/stdc++.h>
using namespace std;

int arr[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n); // 오름차순으로 정렬

    int MAX = INT_MAX;
    for(int i = 0; i < n - 1; i++){ // arr[i]를 선택
        int idx = lower_bound(arr + i,  arr + n, arr[i] + m) - arr; // arr[i] + m보다 크거나 같은 값 중 가장 작은 값을 찾음
        if(idx < n) MAX = min(MAX, arr[idx] - arr[i]);  // arr[i] + m보다 작거나 같은 수가 존재한다면, 기존 m값과 비교하여 더 작은 수를 저장
    }
    cout << MAX;
}   