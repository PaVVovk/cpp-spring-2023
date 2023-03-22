#include <iostream>

using std::endl;
using std::cout;
using std::cin;

bool reserve_memory(int *&dst, size_t N){
    if (dst == nullptr){
        dst = new int[N];
        return true;
    }
    return false;
}

void free_memory(int*& ptr){
    delete [] ptr;
}

int main(){
    int N = 0;
    cin >> N;
    int* ptr = nullptr;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}
