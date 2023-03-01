#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void record(double time, unsigned n){
    std::ofstream out("data2_n.txt", std::ios::app);
    if (out.is_open()){
        out << n << "\t" << time << endl;
    }
    out.close();
} 

void find_two(int* a, int summ, int len){
    int left = 0;
    int right = len - 1;
    while (left < right){
        if (a[left] + a[right] == summ){
            return;
        }
        if (a[left] + a[right] < summ){
            left++;
        } else {
            right--;
        }
    }
} 

int main(){
    double time1 = 0;
    unsigned seed = 1001;
    int s_count = 1000;
    for (int m = 100; m<10100; m += 100){
        int* a = new int[m];
        for (int i = 0; i < m; i ++){
            a[i] = i;
        } 

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 3*m);

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            find_two(a, dstr(rng), m); 
        }
        auto end = std::chrono::steady_clock::now();
  
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time1 = time_span.count();

        record(time1/s_count, m);
        delete [] a;
    }

    return 0;
}