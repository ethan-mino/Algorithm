#include <bits/stdc++.h>
using namespace std;

int arr[21];    // 전체 수열을 저장하는 배열
bool isused[21];    // 숫자의 선택 여부를 저장하는 상태 배얄
int selected[21];   // 선택된 숫자를 저장하는 배열

int n, s, ans = 0;

void seq(int r, int m, int a){  // 길이가 a인 수열을 선택할 때, index r 이상의 범위에서 a-m+1개의 숫자를 선택하는 함수
    if(m == a + 1){ // 수열의 길이만큼 숫자를 선택한 경우
        int sum = 0;
        for(int i = 0; i < a; i++) sum += selected[i];  // 선택된 숫자들을 모두 합함.

        if(sum == s) ans++; // 선택된 숫자들의 합이 s인 경우, 경우의 수 증가
    }else{
        for(int i = r; i < n; i++){
            if(!isused[i]){
                isused[i] = true; selected[m - 1] = arr[i];
                seq(i + 1, m + 1, a);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;

    for(int i = 0; i < n; i++)  cin >> arr[i];
    
    for(int i = 1; i <= n; i++) seq(0, 1, i);
    cout << ans;
}