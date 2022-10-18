// Created by SSAFY on 2022-10-18.

#include <bits/stdc++.h>
using namespace std;

int headCnt[1000010];

// n개의 식당의 고객들을 모두 검사하기 위한 검사자의 최소의 수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> headCnt[i];
    int leaderTestAvailCnt, memberTestAvailCnt;
    cin >> leaderTestAvailCnt >> memberTestAvailCnt;

    // 팀장의 수, 멤버의 수
    long long leaderCnt = 0, memberCnt = 0;

    for(int restaurantIdx =  0; restaurantIdx < n; restaurantIdx++){
        leaderCnt++;
        headCnt[restaurantIdx] -= leaderTestAvailCnt;
        if(headCnt[restaurantIdx] > 0){
            memberCnt += ceil((double) headCnt[restaurantIdx] / memberTestAvailCnt);
        }
    }

    cout << leaderCnt + memberCnt << "\n";
}