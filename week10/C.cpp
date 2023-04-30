#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    int k;
    cin >> k;
    int* value = new int[k];
    int price = 0;
    for (int i = 0; i < k; i++){
        cin >> value[k-i-1];
    }
    //Система монет каноническая, можно использовать жадный алгоритм
    cin >> price;
    int cnt = 0;
    int i = 0;
    while((i < k) and (price > 0)){
        cnt += price / value[i];
        price = price % value[i];
        i++;
    }
    cout << cnt << endl;

    delete [] value;
    return 0;
}