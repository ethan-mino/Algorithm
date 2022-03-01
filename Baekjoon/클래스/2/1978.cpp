#include <bits/stdc++.h>
using namespace std;


bool isPrime(vector<int> & prime, int num){
    bool flag = true;

    if(num <= prime.back()){    
        flag = false;

        for(int i = prime.size() - 1; i >= 0; i--){
            if(prime[i] == num){
                flag = true;
                break;
            }
        }
    }else{
        for(int i = 0; i < prime.size(); i++){
            if(num % prime[i] == 0){
                flag = false;
                break;
            }
        }
    }

    return flag;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int c = 7;
    int cnt = 0;
    
    vector<int> prime = {2, 3, 5, 7};

    for(int i = 0; i < n; i++){
        int a; cin >> a;

        while(c < a){
            if(isPrime(prime, c))
                prime.push_back(c);
            c++;
        }

        if(isPrime(prime, a)){
            cnt++;
        }
    }

    cout << cnt;
}

/*
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
}

*/