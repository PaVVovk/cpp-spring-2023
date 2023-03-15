#include <iostream>
#include <random>

using std::endl;
using std::cout;
using std::cin;

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void print_arr(int* arr, int len){
    for (int i = 0; i < len; i++){
            cout << arr[i] << ' ';
        }
    cout << endl;
}

void forward_step(int* arr, int begin, int end){
    for (int i = begin; i < end; i++){
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
}

void backward_step(int* arr, int begin, int end){
    for (int i = end; i > begin; i--){
        if (arr[i] < arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
    }
}

void shaker(int* arr, int begin, int end){
    while (begin < end){
        forward_step(arr, begin, end);
        end--;
        backward_step(arr, begin, end);
        begin++;
    }
}

bool check_sort(int* arr, int len){
    for (int i = 0; i < len-1; i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    unsigned seed = 1001;
    int total = 0;
    int succ = 0;
    for (int m = 10; m < 5000; m += 100){
        total++;
        int* a = new int[m];

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 2*m);
    
        for (int i = 0; i < m; i++){
            a[i] = dstr(rng);
        }
        //print_arr(a, m);
        shaker(a, 0, m-1);
        //print_arr(a, m);
        if (check_sort(a, m)){
            succ++;
        }
        delete [] a;
    }
    cout << "Total sorts: " << total << endl;
    cout << "Succesful: " << succ << endl;
    cout << "Total = succesful: ";
    if (total == succ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}