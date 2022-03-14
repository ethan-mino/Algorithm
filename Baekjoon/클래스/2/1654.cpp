#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int k, n;

long long cut(long long length){
    long long cnt = 0;
    for(int i = 0; i < k; i++)
        cnt += arr[i] / length;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for(int i = 0; i < k; i++) cin >> arr[i];

    long long high = *max_element(arr, arr + n);
    long long low = 1;

    while(high > low){
        long long length = (high + low) / 2;
        long long cnt = cut(length);
        
        if(cnt >= n && cut(length + 1) < n){
            break;
        }else if(cnt < n){  
            high = length - 1;
        }else if(cnt >= n){
            low = length + 1;
        }
    }
    cout << (high + low) / 2;
}

/*
2 1000
2147483647
2147483647

1 1
802

1 0
802

4 4
1
1
1
1

20 26
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
*/