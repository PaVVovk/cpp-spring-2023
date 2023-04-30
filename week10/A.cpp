#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    int* value = new int[6];
    int price = 0;
    for (auto j: {98, 63, 49, 28, 7, 1}){
        value[price++] = j;
    }

    cin >> price;
    int cnt = 0;
    int i = 0;
    while((i < 6) or (price > 0)){
        cnt += price / value[i];
        price = price % value[i];
        i++;
    }
    cout << cnt << endl;

    delete [] value;
    return 0;
}