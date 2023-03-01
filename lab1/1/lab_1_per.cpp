#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void record(long long time, unsigned n){
    std::ofstream out("data1_1mid.txt", std::ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void search(int* a, int elem, int len){
    for (int i = 0; i < len; i++){
        if (elem == a[i]){
            return;
        }
    }
}

int main(){
    long long time1 = 0;
    unsigned seed = 1001;
    int s_count = 500;
    for (int m = 100; m<1010000; m += 10000){
        time1 = 0;
        int* a = new int[m];
        for (int i = 0; i < m; i ++){
            a[i] = i;
        } 

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);

        for(int i = 0; i < s_count; i++){
            auto begin = std::chrono::steady_clock::now();
            search(a, dstr(rng), m); 
            auto end = std::chrono::steady_clock::now();
  
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/s_count, m);
        delete [] a;
    }

    return 0;
}