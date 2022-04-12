#include <bits/stdc++.h>
using namespace std;

long long arr[1000001];

long long string_to_long(string & str){
    long long result = str[0] - 48;
    for(int i = 1; i < str.size(); i++){
        result = (result * 10) + str[i] - 48;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; 
    
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        reverse(str.begin(), str.end()); // 거꾸로 뒤집음
        arr[i] = stol(str); // long long형으로 변환
    }
    sort(arr, arr + n); // 정렬
    for(int i = 0 ; i < n; i++) cout << arr[i] << "\n";
}   

/* 2
000000000022
000000000023
*/