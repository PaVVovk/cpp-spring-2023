# include <iostream>
# include <fstream>
# include <chrono>
# include <random>
#include <cmath>

using std::endl;
using std::cout;
using std::cin;

int swaps = 0;

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
    swaps++;
}

void record(double time, int N){
    std::ofstream out("data_time2.txt", std::ios::app);
    if (out.is_open())
    {
        out << N << " " << time << "\n";
    }
    out.close();
}

void record(int sw, int N){
    std::ofstream out("data_swap2.txt", std::ios::app);
    if (out.is_open())
    {
        out << N << " " << sw << "\n";
    }
    out.close();
}

int hib(int i){
    return pow(2, i) - 1;
}

void sort(int *arr, int len, int step){
    int i = step;
    int j = 0;
    while (i < len){
        j = i;
        while ((arr[j] < arr[j - step]) and (j >= step)){
            swap(arr[j], arr[j - step]);
            j -= step;
        }
        i += step;
    }
}

void shell_sort(int *arr, int len){
    int i = 0;
    while (hib(i) < len) 
        i++;
    i--;
    while (hib(i) > 0)
    {
        sort(arr, len, hib(i));
        i--;
    }
}

int main(){
    double time1 = 0;
    unsigned seed = 1001;
    int s_count = 250;
    for (int m = 10; m<5500; m += 100){
        time1 = 0;
        int* a = new int[m];

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);

        for (int i = 0; i < m; i++){
            a[i] = dstr(rng);
        }

        for(int i = 0; i < s_count; i++){
            auto begin = std::chrono::steady_clock::now();
            shell_sort(a, m);
            auto end = std::chrono::steady_clock::now();
            
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/s_count, m);
        record(swaps/s_count, m);
        swaps = 0;
        delete [] a;
    }

    return 0;
}