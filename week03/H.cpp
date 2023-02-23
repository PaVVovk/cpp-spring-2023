#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 3
#endif

#ifndef M
#define M 4
#endif

void get_arr(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
}

void print_transposed(int (&arr)[N][M]){
    for (int j = 0; j < M; j++){
        for (int i = 0; i < N; i++){
            cout << arr[i][j];
            if (i < N-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main() { 
    int a[N][M] = {0};
    get_arr(a);
    print_transposed(a);
    return 0;
}