#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Students{
    std::string name;
    int score;
};

void swap(Students& lha, Students& rha){
    Students tmp = lha;
    lha = rha;
    rha = tmp;
}

void sort(Students* arr, int len){
    int i = 1;
    int j = 0;
    while (i < len){
        j = i;
        while ((j >= 1) and (arr[j].score < arr[j - 1].score)){
            swap(arr[j], arr[j - 1]);
            j--;
        }
        j = i;
        while ((j >= 1) and (arr[j].score == arr[j - 1].score) and (arr[j].name < arr[j - 1].name)){
            swap(arr[j], arr[j - 1]);
            j--;
        }
        i++;
    }
}

void filter_arr(Students* &arr, int &len, int filt){
    int new_len = 0;
    for (int i = 0; i < len; i++){
        if (arr[i].score >= filt){
            new_len++;
        }
    }
    Students* new_arr = nullptr;
    if (new_len > 0){
        new_arr = new Students[new_len];
        int j = 0;
        for (int i = 0; i < len; i++){
            if (arr[i].score >= filt){
                new_arr[j] = arr[i];
                j++;
            }
        }
    }
    delete [] arr;
    arr = new_arr;
    len = new_len;
}

int main(){
    int N = 0;
    cin >> N;
    Students* st = new Students[N];
    for (int i = 0; i < N; i++){
        cin >> st[i].name >> st[i].score;
    }
    int M = 0;
    cin >> M;
    filter_arr(st, N, M);
    sort(st, N);
    for (int i = 0; i < N; i++){
        cout << st[i].name << ' ';
    }
    cout << endl;
    delete [] st;
    return 0;
}