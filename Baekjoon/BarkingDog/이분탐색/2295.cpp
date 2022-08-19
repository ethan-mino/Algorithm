#include <bits/stdc++.h>
using namespace std;
int arr[1000];
vector<int> sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++)  // 가능한 두 수의 합을 구한다.
        for(int j = i; j < n; j++)
            sum.push_back(arr[i] + arr[j]);
    
    sort(arr, arr + n); // arr 정렬
    sort(sum.begin(), sum.end());   // 두 수의 합 벡터 정렬 (이분탐색을 수행하기 위해)

    for(int i = n - 1; i >= 0; i--){    // arr[i]의 최댓값을 구한다. (큰 값부터 확인하기 때문에 찾으면 바로 종료)
        for(int j = i; j >= 0; j--){
            int a = arr[i] - arr[j];  
            bool exist = binary_search(sum.begin(), sum.end(), a);  // 이분탐색 수행
            if(exist) {
                cout << arr[i] << "\n";
                return 0;
            }
        }
    }
}   