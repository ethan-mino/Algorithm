#include <bits/stdc++.h>
using namespace std;

#define idx first
#define benefit second

int order[1000], tree1[1000], tree2[1000];
pair<int, int> d[30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, w; cin >> t >> w;
    for(int i = 0; i < t; i++)
        cin >> order[i];

    if(order[t - 1] == 1) tree1[t - 1] = 1;
    else tree2[t - 1] = 1;

    vector<int> move; // 자두가 떨어지는 나무가 바뀌는 지점
    for(int i = t - 2; i >= 0; i--){
        if(order[i] == 1){
            tree1[i] = tree1[i + 1] + 1;
            tree2[i] = tree2[i + 1];
        }else{
            tree2[i] = tree2[i + 1] + 1;
            tree1[i] = tree1[i + 1];
        }
        if(order[i] != order[i + 1]) move.push_back(i);
    }

    // for(int i = 0; i < t; i++) cout << tree1[i] << " ";
    // cout << "\n";

    // for(int i = 0; i < t; i++) cout << tree2[i] << " ";
    // cout << "\n";
    
    for(auto c : move) cout << c << " ";
    cout << "\n";
    reverse(move.begin(), move.end());
    
    d[0] = {-1, tree1[0]};
    for(int i = 1; i <= w; i++){    // i는 이동 가능한 횟수
        int MAX = INT_MIN;

        for(int j = 0; j < move.size(); j++){
             if(move[j] > d[i - 1].idx){
                if(1&i){    // 앞서 이동한 횟수가 짝수인 경우
                    int b = d[i - 1].benefit - (tree1[move[j]] - 1) + tree2[move[j] + 1];
                    if(MAX < b){
                        MAX = b;
                        d[i].benefit = b; 
                        d[i].idx = move[j];
                    }
                    
                }else{  // 홀수인 경우
                    int b = d[i - 1].benefit - (tree2[move[j]] - 1) + tree1[move[j] + 1];
                    if(MAX < b){
                        MAX = b;
                        d[i].benefit = b; 
                        d[i].idx = move[j];
                    }
                }
            }
        }
        cout << "MAX_IDX : " << MAX << "\n";
    }

    int m = INT_MIN;
    for(int i = 0; i <= w; i++) if(m < d[i].benefit) m = d[i].benefit;
    for(int i = 0; i <= w; i++) cout << "(" << d[i].benefit << ", " << d[i].idx << ") ";
    cout <<"\n";
    cout << m << "\n";
   
}   

/* 
17 4
1
1
1
2
2
1
1
1
2
2
2
2
1
1
1
1
1
*/

// 다른 나무에서 떨어질 때마다 이동하는 것이 당연히 더 많은 자두를 먹을 수 있음
// 하지만, 이동 횟수에 제한이 있으므로, 더 많이 움직인다고 많이 먹는 것은 아니며, 가장 많이 먹을 수 있을 때만 움직여함.
// 홀수번 움직이면 2번 나무, 짝수번 움직이면 1번 나무



// n나무, m나무
// 다른 나무에서 자두가 더 많이 떨어질 때 이동
// 최대 ->  
