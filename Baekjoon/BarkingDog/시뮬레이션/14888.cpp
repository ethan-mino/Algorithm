#include <bits/stdc++.h>
using namespace std;

long long num[11];
long long b = LONG_MIN;
long long s = LONG_MAX;

char op[4] = {'+', '-', '*', '/'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    for(int i =0; i < n; i++) cin >> num[i];
    
    vector<char> np;

    for(int i = 0; i < 4; i++){
        int c; cin >> c; 
        // 연산자의 개수만큼 연산자를 벡터에 넣어준다. (ex. 2 1 1 1 -> np = {'+','+','-','*', /'})
        for(int j = 0; j < c; j++) np.push_back(op[i]); 
    }

    sort(np.begin(), np.end()); // next_permutation를 사용하기 위해서는 대상 배열이 정렬되어 있어야 함

    do{
        long long t = num[0];   // 연산식 가장 앞의 정수
        for(int i = 0; i < np.size(); i++){
            switch(np[i]){  // 연산자에 따라 연산 수행
                case '+' : t = t + num [i + 1]; break;  
                case '-' : t = t - num [i + 1]; break;
                case '*' : t = t * num [i + 1]; break;
                case '/' : t = t / num [i + 1]; break;
            }
        }
        b = max(b, t);
        s = min(s, t);
    }while(next_permutation(np.begin(), np.end())); // 각 연산자 수열에 대해 반복
    
    cout << b << "\n" << s;
}