#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int n, m;

// 높이를 height로 했을 때, 가져갈 수 있는 나무의 길이를 계산하는 함수
// 각각의 높이는 10억보다 작거나 같기 때문에 반환형은 long long이 되어야 한다.
long long length(int height){   
    long long l = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] > height) l += arr[i] - height;
    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)  
        cin >> arr[i];
    
    // 가능한 절단기의 범위 설정 (상근이는 필요한 나무를 항상 가져갈 수 있기 때문에 절단기의 최대 높이는 나무의 최대 높이 -1)
    int high = *max_element(arr, arr + m); - 1; 
    int low = 0;

    while(high > low){  // 이분탐색
        int height = (high + low) / 2;
        long long l = length(height);
        
        if(l >= m && length(height + 1) < m){   // m미터의 나무를 자르기 위해서 설정할 수 있는 절단기의 최대 높이인 경우
            break;
        }else if(l < m){  // 나무가 부족한 경우
            high = height - 1;
        }else if(l > m){ // 나무가 충분한 경우
            low = height + 1;
        }
    }
    
    cout << (high + low) / 2;
}

/*
4 5
20 15 10 17

4 5
20 15 10 17

4 3
20 15 10 17

4 1
20 15 10 17

4 4
1 1 1 1

4 17
4 4 4 4
*/

