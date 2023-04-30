#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int mod(int n, int m){ //положительный остаток
    if (n % m >= 0){
        return (n % m);
    }
    return (m + (n % m));
}

int up_div(int n, int m){
    if (n % m == 0){
        return n / m;
    }
    return n / m + 1;
}

int main(){
    int numer, denom = 0;
    cin >> numer >> denom;
    int tmp = 0;
    while (numer != 0){
        tmp = numer;
        cout << up_div(denom, numer) << ' ';
        numer = mod(-denom, numer);
        denom = denom*up_div(denom, tmp);
    }
    cout << endl;
    return 0;
}