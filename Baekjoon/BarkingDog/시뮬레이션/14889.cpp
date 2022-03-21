#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;

int board[20][20];

int ability(vector<int> team1, vector<int> team2){
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < team1.size() - 1; i++){
        for(int j = i + 1; j < team1.size(); j++){
            sum1 += board[team1[i]][team1[j]] + board[team1[j]][team1[i]];
            sum2 += board[team2[i]][team2[j]] + board[team2[j]][team2[i]];
        }
    }
    return abs(sum1 - sum2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    vector<int> np;
    
    for(int i = 0; i < n/2; i++){
        np.push_back(0);
        np.push_back(1);
    }
    sort(np.begin(), np.end());
    
    do{ 
        vector<int> team1, team2;
        for(int i = 0; i < np.size(); i++){
            if(np[i] == 0) team1.push_back(i);
            else if(np[i] == 1) team2.push_back(i);
        }
        ans = min(ans, ability(team1, team2));
    }while(next_permutation(np.begin(), np.end()));
    cout << ans;
}