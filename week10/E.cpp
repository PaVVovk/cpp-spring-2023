#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    int n, k, s = 0;
    cin >> n >> k >> s;
    
    int* st = new int[s];
    for (int i = 0; i < s; i++){
        cin >> st[i];
    }

    int i = 0;
    int point = 0;
    bool flag = false;
    int count = 0;
    while ((point + k < n) and (count >= 0)){
        if ((i < s) and ((st[i] - point) <= k)){
            flag = true;
            i++;
        } else if (flag){
            count++;
            flag = false;
            point = st[i-1];
        } else {
            count = -1;
        }
    }
    cout << count << endl;
    delete [] st;
    return 0;
}