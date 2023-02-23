#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 9
#endif

//Принцип работы функции поиска "одинокого" числа:
//1.Если применить побитовое XOR к паре повторяющихся чисел, то получится 0;
//2.Если применить побитовое XOR к нулю и ненулевому числу, получится число;
//3.XOR коммутативно.

int find_lonely(int (&arr)[N]){
    int odinochka = 0;
    for (int i = 0; i < N; i++){
        odinochka = odinochka ^ arr[i];
    }
    return odinochka;
}

int main() { 
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    cout << find_lonely(a) << endl;
    return 0;
}