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

void triple_sort(int (&arr)[N], int i, int max_len){
    //Сравнение родителя и двух детей в куче
    //для сортировки по возрастанию
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if ((left < max_len) and (arr[max] < arr[left])){
        max = left;
    }
    if ((right < max_len) and (arr[max] < arr[right])){
        max = right;
    }
    swap(arr[max], arr[i]);
}

void cheops_sort(int (&arr)[N], int len){
    //Сортировка по возрастанию
    if (len < 2){
        return;
    }
    for (int i = len/2; i>=0; i--){
        triple_sort(arr, i, len);
    }
    swap(arr[0], arr[len-1]);
    cheops_sort(arr, len-1);
}

int main(){
    int a[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cheops_sort(a, N);
    for (int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}