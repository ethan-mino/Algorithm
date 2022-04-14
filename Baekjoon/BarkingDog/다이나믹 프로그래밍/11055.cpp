#include <bits/stdc++.h>
using namespace std;

int arr[1001], d[1001];
int n;

int sum(int idx){   // idx부터 시작하여 가장 큰 증가 부분 수열의 합을 반환하는 함수
    if(d[idx] != 0)
        return d[idx];
    else{
        int ans = INT_MIN;    // idx번째 원소를 제외한 나머지 가장 큰 수열의 합
        bool biggest = true;    // idx 이후로 arr[idx]보다 큰 원소가 있는지를 나타내는 flag
        for(int i = n - 1; i > idx; i--){
            if(arr[idx] < arr[i]){
                biggest = false;    // idx 이후로 arr[idx]보다 큰 원소가 있음
                ans = max(ans, sum(i)); // arr[idx]보다 큰 원소를 시작점으로 가장 큰 증가 부분 수열의 합을 계산
            }
        }

        if(biggest) d[idx] = arr[idx]; // idx 이후로 arr[idx]보다 큰 것이 하나도 없다면, idx부터 시작하여 가장 큰 증가 부분 수열의 합은 자기 자신 뿐
        else d[idx] = arr[idx] + ans; // 그렇지 않다면 가장 큰 
        return d[idx];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];   // 수열 입력 받음
    for(int i = 0; i < n; i++) sum(i);  // 수열의 각 원소를 시작점으로 잡고, 가장 큰 증가 부분 수열의 합을 구함

    cout << *max_element(d, d + 1001);  // 시작점에 따른 가장 큰 증가 부분의 수열 중 가장 큰 합을 출력
}   

/*
4
3 1 2 3
-> 6

7
2 1 100 97 98 99 101
-> 397
*/