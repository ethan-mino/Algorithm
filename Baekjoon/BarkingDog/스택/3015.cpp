#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        int c; cin >> c;
        arr.push_back(c);
    }

    stack<pair<int, int> > s1;

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        while(!s1.empty() && arr[i] >= s1.top().first)
            s1.pop();
        
        if(!s1.empty()){
            int max = 0;
            for(int j = i + 1; j < s1.top().second; j++){
                if(arr[j] >= max){
                    max = arr[j];
                    cnt++;
                }
            }
            cnt += 1;
        }else{
            int max = 0;
            for(int j = i + 1; j < n; j++){
                if(arr[j] >= max){
                    max = arr[j];
                    cnt++;
                }
            }
        }
        s1.push(pair<int, int>(arr[i], i));
    }

    cout << cnt;
}
// 0 1 2 3 4 5 6
// 2 4 1 3 3 2 4 5 1

// 오른쪽에서 처음으로 자신보다 키가 큰 사람을 찾고 그 사이의 사람은 모두 마주볼 수 있음. 
// 6 3 2 7 8 -> 자신보다 키가 큰 사람 이후의 사람과는 마주칠 수 없음.
// 예외 6 3 2 5 7 -> 6과 2는 마주칠 수 없음.
// 예외 6 4 2 3 5 7
// -> 오름차순만 카운트

// 5 6
// 4 5
// 3 4
// 2 3
// 2 4
// 1 2
// 1 3
// 1 4
// 1 5
// 0 1
