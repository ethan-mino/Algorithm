#include <iostream>
using namespace std;

int func1(int n) { 
    int sum = 0;

    for (int i = 0; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }

    return sum;
}

int func2(int arr[], int n){
    int flag = 0;

    for (int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == 100){
                flag = 1;
                break;
            }
        }
    }

    return flag;
}

int func3(int n){
    for (int i = 1; i * i <= n; i++){
        if(i * i == n) return 1;
    }

    return 0;
}

int func4(int n){
    int val = 1;
    while(2 * val <= n) val *= 2;
    return val;
}

int main(){
    cout << "**********" << " func1 " << "**********" << endl;
    cout << func1(16) << endl;
    cout << func1(34567) << endl;
    cout << func1(27639) << endl;

    cout << "**********" << " func2 " << "**********" << endl;
    int func2_array1 [] = {1, 52, 48};
    int func2_array2 [] = {50, 42};
    int func2_array3 [] = {4, 13, 63, 87};
    cout << func2(func2_array1, 3) << endl;
    cout << func2(func2_array2, 2) << endl;
    cout << func2(func2_array3, 4) << endl;

    cout << "**********" << " func3 " << "**********" << endl;
    cout << func3(9) << endl;
    cout << func3(693953651) << endl;
    cout << func3(756580036) << endl;


    cout << "**********" << " func4 " << "**********" << endl;
    cout << func4(5) << endl;
    cout << func4(97615282) << endl;
    cout << func4(1024) << endl;
}