#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void record(double time, unsigned n){
    std::ofstream out("data3_Bneravn.txt", std::ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

int search(int* a, int elem, int len){
    for (int i = 0; i < len; i++){
        if (elem == a[i]){
            return i;
        }
    }
    return -1;
}


void swap(int &a, int &b){
	int tmp; 
	tmp = a;
    a = b;
    a = tmp;
}

int main(){
    double time1 = 0;
    unsigned seed = 1001;
    int s_count = 500;
    int key = 0;
    int key1 = 0;
    int key2 = 0;
    int res = 0;
    for (int m = 100; m<=101000; m += 1000){
        time1 = 0;
        int* a = new int[m];

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);
        
        for (int i = 0; i < m; i++){
            a[i] = dstr(rng);
        }
        key1 = a[dstr(rng)%(m-1)];
        key2 = a[dstr(rng)%(m-1)];
        auto begin = std::chrono::steady_clock::now();
        for(int i = 0; i < s_count; i++){
            key = dstr(rng);
            if (key%3 == 0){
                key = key1;
            } else if (key%3 == 1){
                key = key2;
            }
            res = search(a, key, m); 
            if (res > 0){
                swap(a[res-1], a[res]);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time1 = time_span.count();
        
        record(time1/s_count, m);
        delete [] a;
    }

    return 0;
}