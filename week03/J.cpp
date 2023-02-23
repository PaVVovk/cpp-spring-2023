#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#ifndef N
#define N 1
#endif

#ifndef M
#define M 3
#endif

void get_arr(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
}

void print_arr(int (&arr)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << arr[i][j];
            if (j < M-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void sort2d(int (&arr)[N][M]){
    int i = 1;
    int j = 0;
    while (i < N*M){
        j = i;
        while ((arr[j/M][j%M] < arr[(j-1)/M][(j-1)%M]) and (j > 0)){
            swap(arr[j/M][j%M], arr[(j-1)/M][(j-1)%M]);
            j--;
        }
        i++;
    }
}

int main() { 
    int a[N][M] = {0};
    get_arr(a);
    sort2d(a);
    print_arr(a);
    return 0;
}