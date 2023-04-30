#include <iostream>
#include <limits.h>

using std::endl;
using std::cout;
using std::cin;

int mat_mult(int* sizes, int len){
    int cost = 0;
    int** mem = new int*[len-1];
    for (int i = 0; i < len-1; i++){
        mem[i] = new int[len-1]{};
    }

    int i, j, q = 0;
    for (int k = 1; k < len-1; k++){
        i = 0;
        j = k;
        while (j < len-1){
            q = INT_MAX;
            for (int p = i; p < j; p++){
                q = std::min(q, mem[i][p] + mem[p+1][j] + sizes[i]*sizes[p+1]*sizes[j+1]);
            }
            mem[i][j] = q;
            i++;
            j++;
        }
    }

    cost = mem[0][len-2];
    for (int i = 0; i < len-1; i++){
        delete [] mem[i];
    }
    delete [] mem;
    return cost;
}

int main(){
    int n = 0;
    cin >> n;
    int* sizes = new int[n];
    for (int i = 0; i < n; i++){
        cin >> sizes[i];
    }
    cout << mat_mult(sizes, n) << endl;
    delete [] sizes;
    return 0;
}