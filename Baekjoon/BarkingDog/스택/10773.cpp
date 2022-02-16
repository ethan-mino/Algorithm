    #include <bits/stdc++.h>
using namespace std;

/* 내가 품 
int s[100001];
int top = 0;

int empty(){
    if(top == 0)
        return 1;
    else   
        return 0;
}

int pop(){
    return s[--top];
}

void push(int n){
    s[top++] = n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    int sum = 0;

    while(k--){
        int n;
        cin >> n;

        if(n == 0)
            pop();
        else
            push(n);
    }

    while(!empty()) sum += pop();
    cout << sum;
}
*/

// 내가 품 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    int sum = 0;

    stack<int> s;

    while(k--){
        int n;
        cin >> n;

        if(n == 0)
            s.pop();
        else
            s.push(n);
    }

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum;
}