#include <bits/stdc++.h>
using namespace std;

pair<int, string> arr[100000];

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     int n; cin >> n;
//     for(int i =0 ; i < n; i++){
//         pair<int, string> p;
//         int c; string s;
//         cin >> c >> s;
//         arr[i] = {c, s};
//     }
    
//     for(int i = 1; i <= 200; i++){
//         for(int j = 0; j < n; j++){
//             if(arr[j].first == i)
//                 cout << arr[j].first << " " << arr[j].second << "\n";
//         }
//     }
// }

bool cmp(const pair<int, string> p1, const pair<int, string> p2){
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    pair<int, string> p;

    for(int i =0 ; i < n; i++){
        cin >> p.first >> p.second;
        arr[i] = p;
    }

    stable_sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << "\n" ;
}

/*
6
21 Junkyu
21 Adidas
21 Dohyun
20 Sunyoung
20 Sanhae
19 Minho

3
21 Junkyu
21 Dohyun
20 Sunyoung

3
21 Dohyun
21 Junkyu
20 Sunyoung

7
20 Sanhae
19 Minho
21 Dohyun
21 Dohyun
21 Junkyu
20 Sunyoung
21 Adidas
*/