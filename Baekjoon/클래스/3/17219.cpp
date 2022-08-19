#include <bits/stdc++.h>
using namespace std;

#define uri first
#define pwd second

bool cmp(pair<string, string> p1, pair<string, string> p2){return p1.uri < p2.uri;} // 사이트의 주소를 기준으로 정렬하는 함수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pair<string, string>> dict;
    for(int i = 0; i < n; i++){
        pair<string, string> p; 
        cin >> p.uri >> p.pwd;
        dict.push_back(p);  // 사이트의 주소와 비밀번호를 입력받아 벡터에 push
    }

    sort(dict.begin(), dict.end(), cmp);    // 사이트의 주소를 기준으로 정렬

    for(int i =0 ; i < m; i++){ // 각각의 비밀번호에 대해 탐색
        string u; cin >> u;

        int left = 0, right = dict.size() - 1;
        int mid = (left + right) / 2;
        
        while(left <= right){   // 이분탐색 수행
            mid = (left + right) / 2;
            if(dict[mid].uri == u) break;
            else if(dict[mid].uri < u) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        cout << dict[mid].pwd << "\n";  // 사이트의 비밀번호 출력
    }
}   