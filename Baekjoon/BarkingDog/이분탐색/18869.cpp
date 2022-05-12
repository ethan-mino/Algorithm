/*
// 소요 시간 1시간 반
#include <bits/stdc++.h>
using namespace std;

#define size first
#define idx second

pair<int, int> u[101][10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0, size; j < n; j++){
            cin >> size;
            u[i][j] = {size, j};    // {행성의 크기, 정렬 전 인덱스}
        }
        sort(&u[i][0], &u[i][n]);   // 각 우주를 행성 크기를 기준으로 정렬
    }

    int ans = 0;    // 균등한 우주 쌍의 개수

    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){ // 두 우주를 선택 (Combination)
            bool equal = true;  // 두 우주가 균등한지 나타내는 Flag 변수
            for(int k = 0; k < n; k++){
                if(u[i][k].idx != u[j][k].idx) {    // 정렬 전 위치가 같지 않다면
                    equal = false;  // 두 우주는 균등하지 않은 우주
                    break;
                }else{  // 정렬 전 위치가 같다면
                    if(i != n - 1){
                        if(u[i][k].size < u[i][k + 1].size != u[j][k].size < u[j][k + 1].size){ // 대소관계 비교
                            equal = false;
                            break;
                        }
                    }
                }

            }
            if(equal) ans++;
        }
    }
    cout << ans << "\n";
}  
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> u(101, vector<int>(0));

void compression(vector<int>& v){   // 벡터에 대해 좌표 압축을 수행하는 함수
    vector<int> tmp(v.size()); 
    copy(v.begin(), v.end(), tmp.begin());  // v를 tmp 벡터에 copy

    sort(tmp.begin(), tmp.end());   // tmp 벡터를 오름차순 정렬
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());   // 중복 제거

    for(int i = 0; i < v.size(); i++){  // X'i 계산
        int idx = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();  
        v[i] = idx;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0, size; j < n; j++){
            cin >> size;
            u[i].push_back(size);
        }
        compression(u[i]);  // 각각의 우주에 대해 좌표 압축 수행
    }

    int ans = 0;
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){ // 두 우주가 균등한지 확인 (Combination)
            if(u[i].size() == u[j].size()){ // 좌표 압축 후, 좌표의 개수가 같을 때만 균등할 수 있음
                bool equal = true;  // 두 우주가 균등한지를 나타내는 Flag 변수
                for(int k = 0; k < u[i].size(); k++){   // 각각의 좌표 압축 결과를 비교
                    if(u[i][k] != u[j][k]) equal = false;   // 결과가 다르다면, 두 우주가 균등하지 않은 것
                }
                if(equal) ans++;
            }
        }
    }
    cout << ans;
}   

/*
3 3
1 1 1
3 3 3
2 2 2
-> 3

2 5
1 1 1 2 3
1 1 1 1 2
-> 0
*/