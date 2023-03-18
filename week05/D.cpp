#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void input_array(int* ptr, size_t N){
    for (int i = 0; i < N; i++){
        cin >> ptr[i];
    }
};

void reverse(int* ptr, size_t N){
    for (int i = 0; i < N/2; i++){
        swap(ptr[i], ptr[N-i-1]);
    }
};

void print(const int* ptr, size_t N){
    for (int i = 0; i < N; i++){
        cout << ptr[i] << ' ';
    }
    cout << endl;
};

int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    ptr = new int[N];
    
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);

    delete [] ptr;
    return 0;
}