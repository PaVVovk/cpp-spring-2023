#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int n = 0;
    cin >> n;
    
    int* st = new int[n];
    int* fin = new int[n];
    int j = 0;
    
    for (int i = 0; i < n; i++){
        j = i;
        cin >> st[i];
        cin >> fin[i];
        while ((j > 0) and (fin[j-1] > fin[j])){ //сразу сортируем лекции по возрастанию времени окончания
            swap(fin[j], fin[j-1]);
            swap(st[j], st[j-1]);
            j--;
        }
    }

    j = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (st[i] >= fin[j]){
            j = i;
            cnt++;
        }
    }
    cout << cnt << endl;

    delete [] st;
    delete [] fin;
    return 0;
}