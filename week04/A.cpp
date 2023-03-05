#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 10
#endif

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void gnome_sort(int (&a)[N]){
    //Сортировка по возрастанию
    int i = 1;
    while (i < N){
        if ((i > 0) and (a[i-1] > a[i])){
            swap(a[i-1], a[i]);
            i--;
        } else {
            i++;
        }
    }
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    gnome_sort(a);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}