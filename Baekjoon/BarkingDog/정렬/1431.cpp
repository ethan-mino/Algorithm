#include <bits/stdc++.h>
using namespace std;

int s(const string & str){  // 자리수 합을 구하는 함수
    int sum = 0;
    for(int i = 0; i < str.size(); i++)
        if(str[i] >= 48 && str[i] <= 57)    // 해당 문자가 숫자인 경우, 더해줌
            sum += str[i] - 48;
    return sum;
}

bool cmp(const string& a, const string &b){
    int len1 = a.size(), len2 = b.size();
    if(len1 == len2){   // 길이가 같으면
        int s1 = s(a), s2 = s(b);
        if(s1 == s2) return a < b;  // 자리수 합이 같은 경우, 사전순으로 정렬
        else return s1 < s2;    // 자리수 합이 같지 않으면, 자리수 합으로 정렬
    }else return len1 < len2;   // 길이로 정렬
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string arr[50];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) cout << arr[i] << "\n";
}   