#include <iostream>

using std::endl;
using std::cout;
using std::cin;

const int costs[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

void bar_cost(int n){
    int* r = new int[n+1];
    int* s = new int[n+1];
    int i, j, q, tmp;
    r[0] = 0;
    for(j = 1; j <= n; j++){
        q = 0;
        for(i = 0; i <= std::min(j, 10); i++){
            if (q < costs[i] + r[j-i]){
                q = costs[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j]=q;
    }
    tmp = n;
    while(tmp > 0){
        cout << s[tmp];
        tmp -= s[tmp];
        if(tmp > 0){
            cout << ' ';
        }
    }
    cout << endl;
    delete [] r;
    delete [] s;
}

int main(){
    int n = 0;
    cin >> n;
    bar_cost(n);
    return 0;
}