#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void resize(int* &arr, int &len, int new_len){
    int* new_arr = new int[new_len];
    for (int i = 0; i < len; i++){
        new_arr[i] = arr[i];
    }
    delete [] arr;
    arr = new_arr;
    len = new_len;
}

int main(){
    int* arr = new int[1];
    int len = 0;
    int elem = 0;
    cin >> elem;
    while (elem != 0){
        resize(arr, len, len+1);
        arr[len-1] = elem;
        cin >> elem;
    }
    for (int i = 0; i < len-1; i++){
        cout << (*(arr+i) - *(arr+i+1)) << ' ';
    }
    cout << endl;
    delete [] arr;
    return 0;
}