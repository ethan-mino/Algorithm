// Created by SSAFY on 2022-10-18.

#include <bits/stdc++.h>
using namespace std;

struct Outsourcing{
    int duration, cost;
};

Outsourcing outsourcings[16];
int maxCost = INT_MIN;
int n;

void work(int day, int totalCost){
    if(maxCost < totalCost) maxCost = totalCost;
    if(day < n){
        work(day + 1, totalCost);

        int duration = outsourcings[day].duration;
        int cost = outsourcings[day].cost;
        int endDay = day + duration - 1;
        if(endDay < n) work(day + duration, cost + totalCost);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> outsourcings[i].duration >> outsourcings[i].cost;

    work(0, 0);
    cout << maxCost << "\n";
}
