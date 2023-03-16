#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    int* arr;
    int len = 0;
    cin >> *(arr+len);
    while (*(arr+len) != 0){
        len++;
        cin >> *(arr+len);
    }
    for (int i = 0; i < len-1; i++){
        cout << (*(arr+i) - *(arr+i+1)) << ' ';
    }
    cout << endl;
    return 0;
}