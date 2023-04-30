#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void record(double time, unsigned n){
    std::ofstream out("data1_2worst.txt", std::ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void bi_search(int* a, int elem, int len){
    int left = 0;
    int right = len - 1;
    int middle = 0;
    while (left <= right){
        middle = (left + right)/2;
        if (elem == a[middle]){
            return;
        }
        if (elem < a[middle]){
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
} 

int main(){
    double time1 = 0;
    unsigned seed = 1001;
    int s_count = 100000;
    for (int m = 100; m<1001000; m += 1000){
        int* a = new int[m];
        for (int i = 0; i < m; i ++){
            a[i] = i;
        } 

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            bi_search(a, -1, m); 
        }
        auto end = std::chrono::steady_clock::now();
  
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time1 = time_span.count();

        record(time1/s_count, m);
        delete [] a;
    }

    return 0;
}