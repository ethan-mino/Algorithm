#include <bits/stdc++.h>
using namespace std;

int snack[1000010];
int m, n; 
long long snack_length(int L){    // 조카 1명에게 줄 막대 과자의 길이가 X일 때, 과자를 줄 수 있는 조카의 수를 반환
    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += snack[i] / L;
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> snack[i];

    int high = *max_element(snack, snack + n);
    int low = 1;
    while(low < high){
        int mid = (high + low + 1) / 2;
        if(snack_length(mid) >= m){  // 더 많은 조카들에게 나누어줄 수 있는 경우
            low = mid;  // 과자의 길이를 늘림
        }else if(snack_length(mid) < m){
            high = mid - 1; // 과자의 길이를 줄임
        }
    }

    int length = (high + low) / 2;
    if(snack_length(length) >= m) cout << length << "\n"; // 길이가 length인 과자들 M명 이상에게 나누어줄 수 있는 경우 
    else cout << 0 << "\n"; // 과자를 M명에게 나누어 줄 수 없는 경우
}   

/*
1 4
1 1000000000 1000000000 1000000000
-> 1000000000
*/