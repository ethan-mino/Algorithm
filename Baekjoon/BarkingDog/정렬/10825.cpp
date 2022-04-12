#include <bits/stdc++.h>
using namespace std;

typedef struct{string name; int kor, eng, math;} student;

bool cmp(const student s1, const student s2){
    if(s1.kor == s2.kor){
        if(s1.eng == s2.eng){
            if(s1.math == s2.math) return s1.name < s2.name;
            else return s1.math > s2.math;
        }else return s1.eng < s2.eng;
    }
    else return s1.kor > s2.kor;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<student> v;
    for(int i = 0; i < n; i++){
        student s; cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }    
    sort(v.begin(), v.end(), cmp);
    for(auto c : v) cout << c.name << "\n";
}   
