#include <iostream>

using std::endl;
using std::cout;
using std::cin;

const int costs[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int bar_cost(int n){
    int* r = new int[n+1];
    int i, j, q;
    r[0] = 0;
    for(j = 1; j <= n; j++){
        q = 0;
        for(i = 0; i <= std::min(j, 10); i++){
            q = std::max(q, costs[i] + r[j-i]);
        }
        r[j] = q;
    }
    int cost = r[n];
    delete [] r;
    return cost;
}

int main(){
    int n = 0;
    cin >> n;
    cout << bar_cost(n) << endl;
    return 0;
}