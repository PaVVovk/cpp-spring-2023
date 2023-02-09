#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int numb = 0;
    int x = 0;
    cin >> x;
    while (x != 0){
        if (x % 2 == 0){
            numb++;
        }
        cin >> x;
    }
    cout << numb << endl;
    return 0;
}