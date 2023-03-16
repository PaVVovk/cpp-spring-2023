#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    double* ptr;
    *ptr = 0;
    cout << ptr << ' ' << *ptr << endl;
    cout << (ptr-3) << ' ' << *(ptr-3) << endl;
    cout << (ptr+5) << ' ' << *(ptr+5) << endl;
    return 0;
}