#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int selected[8];
bool isused[8];

void back(int r, int th){  // 인덱스 idx부터 수열의 길이가 M인 수열을 모두 구하는 함수
    if(th == m + 1){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        vector<int> v;  // th번째에 선택한 숫자를 저장하는 벡터

        for(int i = r; i < n; i++){
            if(!isused[i] && (v.size() == 0 || (v.size() > 0 && v.back() != arr[i]))){  
                v.push_back(arr[i]);
                isused[i] = true; selected[th - 1] = arr[i]; 
                back(i + 1, th + 1);
                isused[i] = false; 
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n); // 수열이 사전 순으로 증가하는 순서로 출력되도록 정렬
    back(0, 1);
}
