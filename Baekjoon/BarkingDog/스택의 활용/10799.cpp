#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int idx;
    int lazer;
}elem;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<elem> v;
    int sum = 0;

    for(int i = 0; i < str.length(); i++){        
        if(str[i] == '('){
            elem e;
            e.idx = i; e.lazer = 0;
            v.push_back(e);
        }else if(i > 0 && str[i - 1] == '('){
            v.pop_back();

            for(int i = 0; i < v.size(); i++){
                v[i].lazer++;
            }
        }
        else{
            if(v.size() != 0){
                elem e = v.back();
                v.pop_back();

                sum += e.lazer + 1;
            }
        }
    }

    cout << sum;
}

/*
    typedef long long ll;
    using namespace std;
    string s;
    ll ans = 0;
    stack<char> st;
    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        if (s[i]=='(')
        st.push(s[i]);
        else {
        if (s[i-1] == '(') { // 레이저일 경우
            st.pop(); // 앞에서 막대라고 착각하고 stack에 s[i]를 넣었으므로 pop
            ans+=st.size(); // 막대의 개수만큼 ans에 추가
        }
        else { // 막대의 끝일 경우
            st.pop();  // 막대의 개수를 1 감소
            ans++; // 막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
        }
        }
    }
    cout << ans << "\n";
    return 0;
    }
*/