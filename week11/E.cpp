#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;

int main(){
    std::string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    int** T = new int*[n+1];
    for (int i = 0; i <= n; i++){
        T[i] = new int[m+1]{};
    }

    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            if (s1[i-1] == s2[j-1]){
                T[i][j] = T[i-1][j-1] + 1;
            } else {
                T[i][j] = std::max(T[i-1][j], T[i][j-1]);
            }
        }
    }
    cout << T[n][m]*100/std::min(n, m) << endl;

    for (int i = 0; i <= n; i++){
        delete [] T[i];
    }
    delete [] T;
    return 0;
}