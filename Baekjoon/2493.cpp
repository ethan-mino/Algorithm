#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int n;
    int idx;
}elem;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<elem> s;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;

        elem e;
        e.n = c;
        e.idx = i + 1;

        while(!s.empty() && s.top().n < c){
            s.pop();
        }

        if(s.empty())
            cout << 0 << " ";
        else
            cout << s.top().idx << " ";
        s.push(e);
    }
}

/*
    #define X first
    #define Y second

    int N;
    stack<pair<int,int>> tower;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N;  
        tower.push({100000001, 0});
        for (int i = 1; i <= N; i++) {
            int height;
            cin >> height;
            while (tower.top().X < height)
            tower.pop();    
            cout << tower.top().Y << " ";
            tower.push({height, i});      
        }
    }
*/