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
    long s = 0;
    cin >> s;
    int n = 0;
    cin >> n;
    
    int* files = new int[n];
    int j = 0;
    
    for (int i = 0; i < n; i++){
        j = i;
        cin >> files[i];
        while ((j > 0) and (files[j-1] > files[j])){ //сортируем файлы по возрастанию
            swap(files[j], files[j-1]);
            j--;
        }
    }

    j = 0;
    s -= files[j];
    while (s > 0){
        j++;
        s -= files[j];
    }
    cout << j << endl;
    delete [] files;
    return 0;
}