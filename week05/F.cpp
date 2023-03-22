#include <iostream>
#include <cstring>

using std::endl;
using std::cout;
using std::cin;

char* resize(const char* buf, size_t size, size_t new_size){
    char* new_buf = new char[new_size];
    int i = 0;
    while (i < new_size){
        if (i < size){
            new_buf[i] = buf[i];
        }
        i++;
    }
    delete [] buf;
    return new_buf;
}

int main(){
    char *a = new char[10];
    a = resize(a, 10, 20);
    delete [] a;
    return 0;
}